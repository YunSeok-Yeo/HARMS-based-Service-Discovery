//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include <carray.h>
#include <cdisplaystring.h>
#include <cenvir.h>
#include <cgate.h>
#include <clistener.h>
#include <cmsgpar.h>
#include <cobjectfactory.h>
#include <cregistrationlist.h>
#include <csimulation.h>
#include <Compat.h>
#include <distrib.h>
#include <Ieee802Ctrl_m.h>
#include <onstartup.h>
#include <PortableDevice.h>
#include <regmacros.h>
#include <simutil.h>
#include <stddef.h>
//#include <string.h>
#include <Wireless.h>
#include <cstdio>
#include <cstdlib>

Define_Module(PortableDevice);

/*
 *  Generate device ID and its own services.
 *
 *  And make Hello packet.
 *
 *  CustomPacket is customized version of cMessage
 */
simsignal_t PortableDevice::sentPkSignal = registerSignal("sentPk");
simsignal_t PortableDevice::rcvdPkSignal = registerSignal("rcvdPk");


void PortableDevice::initialize()
{

    ID = getId();
    Service = intuniform(0, SERVICENUM - 1);
    MacAddress.setAddress(getParentModule()->getSubmodule("wlan")->getSubmodule("mac")->par("address"));
    int APs = getParentModule()->getParentModule()->par("APs");


    hello = GeneratePacket("hello", 255, 0, HELLO, 1);
    nodeRegister = GeneratePacket("nodeRegister", 255, APSERVICE, REGISTER, 5);
    query =  GeneratePacket("query", 255, intuniform(0, SERVICENUM - 1), QUERY, 5);

    helloTimer = new CustomPacket("helloTimer");
    registerTimer = new CustomPacket("registerTimer");
    queryTimer = new CustomPacket("queryTimer");

    query->SetLocation(intuniform(0, APs));

    string s;
    stringstream out;
    out << ID <<"," << Service << "|";
    s = out.str();
    hello->SetLastHop(s);
    nodeRegister->SetLastHop(s);
    query->SetLastHop(s);



    scheduleAt(uniform(1, 5), helloTimer);
    scheduleAt(uniform(10, 15), registerTimer);
    scheduleAt(uniform(20, 25), queryTimer);


    //getDisplayString()
}

void PortableDevice::UpdateTables(string lastHop, string macAddress, int hopCount){

    string token, secondToken;
    size_t pos, secondPos;
    string delimiter = "|", secondDelimiter = ",";
    while ((pos = lastHop.find(delimiter)) != string::npos) {

        token = lastHop.substr(0, pos);

        secondPos = token.find(secondDelimiter);
        secondToken = token.substr(0, secondPos);

        int id = atoi(secondToken.c_str());

        token.erase(0, secondPos + secondDelimiter.length());

        routingTable.UpdateEntry(id, macAddress, hopCount--);
        nodeTable.UpdateEntry(id, atoi(token.c_str()), 0, 10);

        lastHop.erase(0, pos + delimiter.length());
    }


}
void PortableDevice::UpdateRoutingTable(string routingInfo, string macAddress){
    string token, secondToken;
    size_t pos, secondPos;
    string delimiter = "|", secondDelimiter = ",";
    while ((pos = routingInfo.find(delimiter)) != string::npos) {

        token = routingInfo.substr(0, pos);

        secondPos = token.find(secondDelimiter);
        secondToken = token.substr(0, secondPos);

        token.erase(0, secondPos + secondDelimiter.length());

        int id = atoi(secondToken.c_str());
        int hopCount = atoi(token.c_str()) + 1;

        routingTable.UpdateEntry(id, macAddress, hopCount);

        routingInfo.erase(0, pos + delimiter.length());
    }

}
void PortableDevice::UpdateNodeTable(string nodeInfo){
    string token, secondToken;
    size_t pos, secondPos;
    string delimiter = "|", secondDelimiter = ",";
    while ((pos = nodeInfo.find(delimiter)) != string::npos) {

        token = nodeInfo.substr(0, pos);

        secondPos = token.find(secondDelimiter);
        secondToken = token.substr(0, secondPos);

        token.erase(0, secondPos + secondDelimiter.length());

        int id = atoi(secondToken.c_str());
        int service = atoi(token.c_str());

        nodeTable.UpdateEntry(id, service, 0, 10);

        nodeInfo.erase(0, pos + delimiter.length());
    }

}
void PortableDevice::handleMessage(cMessage *msg)
{
    CustomPacket *packet = check_and_cast<CustomPacket *>(msg);


    if(msg->isSelfMessage())
    {
        if(msg == helloTimer){
            currentState = HELLO;
            EV << ID << " Send Hello Message" << endl;

            forwardMessage(hello);

            UpdateDisplay();
        }
        else if(msg == registerTimer)
        {
            int targetId = nodeTable.FindService(APSERVICE);

            EV << "Node:" << ID << " send message " << nodeRegister << " to register" << "\n";
            currentState = REGISTER;
            nodeRegister->SetDestination(targetId != -1 ? targetId : 255);
            nodeRegister->setKind(3);

            forwardMessage(nodeRegister);
        }
        else
        {
            if(nodeTable.FindService(query->GetDestinationService()) == -1 && query->GetDestinationService() != Service){
                // This is selfMessage
                EV << "Node:" << ID << " send message " << query << " to find Service:" << query->GetDestinationService() << "\n";
                currentState = QUERY;
                int APId = nodeTable.FindService(APSERVICE);
                query->SetDestination( APId != -1 ? APId : 255 );
                forwardMessage(query);
            }else{
                EV << "Node:" << ID << " already find Service:" << query->GetDestinationService() << "\n";
                currentState = -1;
                delete query;
            }
        }



        delete packet;

        UpdateDisplay();

        return;
    }

    emit(rcvdPkSignal, msg);

    if(cache.checkEntry(packet->GetSource(), packet->GetSeqNum()) ||
            (packet->GetOriginSourceId() != 0 ? cache.checkEntry(packet->GetOriginSourceId(), packet->GetOriginSourceSeqNum()): false))
    {
        //This node already forward this message
        delete packet;
        return;
    }

    packet->SetHopCount(packet->GetHopCount() + 1);
    packet->SetMaxHopCount(packet->GetMaxHopCount() - 1);

    Ieee802Ctrl *ctrl = check_and_cast<Ieee802Ctrl *>(packet->getControlInfo());
    //Update it's tables (Routing, Node) and cache
    UpdateTables(packet->GetLastHop(), ctrl->getSrc().str(), packet->GetHopCount());
    cache.AddEntry(packet->GetSource(), packet->GetSeqNum());


    switch(packet->GetType()){
    case QUERY:
        Query(packet);
        break;
    case REPLY:
        Reply(packet);
        break;
    case NOTICE:
        Notice(packet);
        break;
    case RETRANSMIT:
        Retransmit(packet);
        break;
    case HELLO:
        Hello(packet);
        break;
    case REGISTER:
        Register(packet);
        break;
    default:
        delete packet;
        break;
    }
}
void PortableDevice::Register(CustomPacket *packet){

    if(packet->GetMaxHopCount() <= 0)
    {
        CustomPacket *notice = GeneratePacket("notice", packet->GetSource(), packet->GetDestinationService(), NOTICE, packet->GetHopCount());
        stringstream out;

        out << ID << "," << Service << "|";
        notice->SetLastHop(out.str());
        notice->SetOriginSourceSeqNum(packet->GetSeqNum());
        notice->setKind(1);

        forwardMessage(notice);
        delete packet;
    }
    else
    {
        string lastHop = packet->GetLastHop();


        //Now it should forward packet to proper neighbors
        //Check whether there is route or not for specific service
        stringstream out;

        //Add its service information
        out << lastHop << ID << "," << Service << "|";
        lastHop = out.str();
        packet->SetLastHop(lastHop);

        if(packet->GetDestination() == 255){
            int targetId = nodeTable.FindService(APSERVICE);
            packet->SetDestination(targetId != -1 ? targetId : 255);
        }

        forwardMessage(packet);
    }
}
void PortableDevice::Hello(CustomPacket *packet){
    CustomPacket *reply = GeneratePacket("reply", packet->GetSource(), 0, REPLY, 1);
    stringstream out;

    out << ID << "," << Service << "|";
    reply->SetLastHop(out.str());

    //EV << nodeTable.GetEntries() << endl;
    //EV << routingTable.GetEntries() << endl;

    cMsgPar *nodeInfo = new cMsgPar("nodeInfo");
    cMsgPar *routingInfo = new cMsgPar("routingInfo");
    nodeInfo->setStringValue(nodeTable.GetEntries().c_str());
    routingInfo->setStringValue(routingTable.GetEntries().c_str());
    reply->addPar(nodeInfo);
    reply->addPar(routingInfo);
    reply->setKind(0);

    forwardMessage(reply);
    delete packet;
}
void PortableDevice::Retransmit(CustomPacket *packet){
    if(packet->GetProxy() != ID)
    {
        forwardMessage(packet);
    }
    else
    {
        EV << "Node:" << ID << " get retransmit packet" <<  endl;
        CustomPacket *replace = GeneratePacket("replace", packet->GetDestination(), packet->GetDestinationService(), QUERY, 5);
        replace->SetOriginSourceId(packet->GetSource());
        replace->SetOriginSourceSeqNum(packet->GetOriginSourceSeqNum());
        forwardMessage(replace);
        //forwardMessage(retransmit);

        delete packet;
    }
}
void PortableDevice::Notice(CustomPacket *packet){

    if(packet->GetDestination() != ID)
    {
        stringstream out;
        out << packet->GetLastHop() << ID << "," << Service << "|";
        packet->SetLastHop(out.str());

        forwardMessage(packet);
    }
    else
    {
        if(packet->getKind() == 2 /*|| currentState == REGISTER*/ ){
            EV << "Node:" << ID << " can not find service:" << Service << endl;
            EV << "Node:" << ID << " retransmit packet to find service:" << Service << endl;
            CustomPacket *retransmit = GeneratePacket("retransmit", packet->GetSource(), packet->GetDestinationService(), RETRANSMIT, packet->GetHopCount());
            retransmit->SetProxy(packet->GetSource());
            retransmit->SetOriginSourceSeqNum(packet->GetOriginSourceSeqNum());
            forwardMessage(retransmit);
        }

        delete packet;
    }
}
void PortableDevice::Reply(CustomPacket *packet){
    if(packet->GetDestination() != ID)
    {
        stringstream out;
        out << packet->GetLastHop() << ID << "," << Service << "|";
        packet->SetLastHop(out.str());

        forwardMessage(packet);
    }
    else
    {
        //EV << "kind: " << packet->getKind() << endl;
        // 0: hello, 1: register, 2: query
        int kind = packet->getKind();
        if(kind == 0){
            EV << ID << " Get Hello Reply Message" << endl;
            cArray arr = packet->getParList();

            cMsgPar *nodeInfo = (cMsgPar *)arr[arr.find("nodeInfo")];
            cMsgPar *routingInfo = (cMsgPar *)arr[arr.find("routingInfo")];

            Ieee802Ctrl *ctrl = check_and_cast<Ieee802Ctrl *>(packet->getControlInfo());

            UpdateRoutingTable(routingInfo->stringValue(), ctrl->getSrc().str());
            UpdateNodeTable(nodeInfo->stringValue());

            arr.remove(nodeInfo);
            arr.remove(routingInfo);
            delete nodeInfo;
            delete routingInfo;

        }else if(kind == 2){
            EV << "Node:" << ID << " find Service:" << Service << "\n";
            currentState = -1;
        }
        UpdateDisplay();
        delete packet;
    }
}
CustomPacket* PortableDevice::GeneratePacket(const char* name, int destinationId, int destinationService, int type, int maxHopCount){

    CustomPacket *newPacket = new CustomPacket(name);
    newPacket->SetDestination(destinationId);
    newPacket->SetDestinationService(destinationService);
    newPacket->SetSource(ID);
    newPacket->SetSeqNum(seqNum++);
    newPacket->SetType(type);
    newPacket->SetMaxHopCount(maxHopCount);
    newPacket->SetHopCount(0);

    return newPacket;
}
void PortableDevice::Query(CustomPacket *packet){
    int sourceId = packet->GetSource();
    int maxHopCount = packet->GetMaxHopCount();
    int targetId = ID;


    if(Service == packet->GetDestinationService() || (targetId = nodeTable.FindService(packet->GetDestinationService())) != -1)
    {
        // This node has a target service.

        CustomPacket *reply = GeneratePacket("reply", sourceId, 0, REPLY, packet->GetHopCount());
        stringstream out;

        out << targetId << "," << packet->GetDestinationService() << "|"; //To reach destination service, Source should send packet to this node.
        reply->SetLastHop(out.str());
        reply->setKind(2);

        forwardMessage(reply);
        delete packet;
    } //limit hop
    else if(maxHopCount <= 0)
    {
        CustomPacket *notice = GeneratePacket("notice", sourceId, packet->GetDestinationService(), NOTICE, packet->GetHopCount());
        stringstream out;

        out << ID << "," << Service << "|";
        notice->SetLastHop(out.str());
        notice->SetOriginSourceSeqNum(packet->GetSeqNum());
        notice->setKind(2);

        forwardMessage(notice);
        delete packet;
    }
    else
    {
        string lastHop = packet->GetLastHop();


        //Now it should forward packet to proper neighbors
        //Check whether there is route or not for specific service
        stringstream out;

        //Add its service information
        out << lastHop << ID << "," << Service << "|";
        lastHop = out.str();
        packet->SetLastHop(lastHop);


        forwardMessage(packet);
    }

}


void PortableDevice::forwardMessage(CustomPacket *packet)
{
    MACAddress destMACAddress;

    //Boradcast
    if(packet->GetDestination() == 255)
    {
        destMACAddress.setBroadcast();
    }
    else
    {
        //find and set macaddress
        string nextHop = routingTable.FindPath(packet->GetDestination());
        if(nextHop.length() == 0)
            destMACAddress.setBroadcast();
        else
            destMACAddress.setAddress(nextHop.c_str());
    }
    Ieee802Ctrl *etherctrl = new Ieee802Ctrl();
    etherctrl->setDest(destMACAddress);
    etherctrl->setSrc(MacAddress);

    packet->removeControlInfo();
    packet->setControlInfo(etherctrl);
    emit(sentPkSignal, packet);

    EV << "Node " << MacAddress << " send packet to " << destMACAddress << endl;

    send(packet, "out");
}
void PortableDevice::UpdateDisplay()
{
    char buf[40];
    sprintf(buf, "My Service: %d, Current State: %d", Service, currentState);
    getDisplayString().setTagArg("t",0,buf);
}
