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

#include "PortableDevice.h"
#include <string.h>
Define_Module(PortableDevice);

/*
 *  Generate device ID and its own services.
 *
 *  And make Hello packet.
 *
 *  CustomPacket is customized version of cMessage
 */

void PortableDevice::initialize()
{

    ID = getId();
    Service = intuniform(0, 10);


    CustomPacket *hello = GeneratePacket("hello", 255, 0, HELLO, 1);
    timer = new CustomPacket("timer");
    query = GeneratePacket("query", 255, APSERVICE, QUERY, 5);

    string s;
    stringstream out;
    out << ID <<"," << Service << "|";
    s = out.str();
    hello->SetLastHop(s);
    query->SetLastHop(s);

    currentState = HELLO;
    EV << ID << " Send Hello Message" << endl;
    forwardMessage(hello);

    if(ID % 2 == 0 && strstr(getFullName(), "AP") == NULL){
        scheduleAt(uniform(1, 5), timer);
    }
    else
    {
        delete query;
    }
    //getDisplayString()
}

void PortableDevice::UpdateTables(string lastHop, int gateId, int hopCount){
    string token, secondToken;
    size_t pos, secondPos;
    string delimiter = "|", secondDelimiter = ",";
    while ((pos = lastHop.find(delimiter)) != string::npos) {

        token = lastHop.substr(0, pos);

        secondPos = token.find(secondDelimiter);
        secondToken = token.substr(0, secondPos);

        int id = atoi(secondToken.c_str());

        token.erase(0, secondPos + secondDelimiter.length());


        routingTable.UpdateEntry(id, gateId, hopCount);
        nodeTable.UpdateEntry(id, atoi(token.c_str()), 0, 10); // How to decrease life time??

        lastHop.erase(0, pos + delimiter.length());
    }

}
void PortableDevice::handleMessage(cMessage *msg)
{
    CustomPacket *packet = check_and_cast<CustomPacket *>(msg);


    if(msg->isSelfMessage())
    {
        if(nodeTable.FindService(APSERVICE) == -1){
            // This is selfMessage
            EV << "Node:" << ID << " send message " << query << " to find Service:" << Service << "\n";
            currentState = QUERY;
            forwardMessage(query);
        }else{
            currentState = -1;
            delete query;
        }


        delete packet;


        return;
    }

    if(cache.checkEntry(packet->GetSource(), packet->GetSeqNum()) ||
            (packet->GetOriginSourceId() != 0 ? cache.checkEntry(packet->GetOriginSourceId(), packet->GetOriginSourceSeqNum()): false))
    {
        //This node already forward this message
        delete packet;
        return;
    }

    packet->SetHopCount(packet->GetHopCount() + 1);
    packet->SetMaxHopCount(packet->GetMaxHopCount() - 1);

    //Update it's tables (Routing, Node) and cache
    UpdateTables(packet->GetLastHop(), gateBaseId("g$o") + packet->getArrivalGate()->getIndex(), packet->GetHopCount());
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
    }
}
void PortableDevice::Hello(CustomPacket *packet){
    CustomPacket *reply = GeneratePacket("reply", packet->GetSource(), 0, REPLY, 1);
    stringstream out;

    out << ID << "," << Service << "|";
    reply->SetLastHop(out.str());

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
        if(currentState == QUERY){
            EV << "Node:" << ID << " can not find service:" << Service << endl;
            EV << "Node:" << ID << " retransmit packet to find service:" << Service << endl;
            CustomPacket *retransmit = GeneratePacket("retransmit", packet->GetSource(), packet->GetDestinationService(), RETRANSMIT, 5);
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
        if(currentState == HELLO){
            EV << ID << " Get Hello Message" << endl;
        }else if(currentState == QUERY){
            EV << "Node:" << ID << " find Service:" << Service << "\n";
        }
        currentState = -1;
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

    return newPacket;
}
void PortableDevice::Query(CustomPacket *packet){
    int sourceId = packet->GetSource();
    int maxHopCount = packet->GetMaxHopCount();
    int targetId = ID;
    string lastHop = packet->GetLastHop();

    //limit hop
    if(packet->GetDestination() != 255 && packet->GetDestination() != ID)
    {
        forwardMessage(packet);
    }
    else if(Service == packet->GetDestinationService() || (targetId = nodeTable.FindService(packet->GetDestinationService())) != -1)
    {
        // This node has a target service.

        CustomPacket *reply = GeneratePacket("reply", sourceId, 0, REPLY, 5);
        stringstream out;

        out << targetId << "," << packet->GetDestinationService() << "|"; //To reach destination service, Source should send packet to this node.
        reply->SetLastHop(out.str());

        forwardMessage(reply);
        delete packet;
    }
    else if(maxHopCount <= 0)
    {
        CustomPacket *notice = GeneratePacket("notice", sourceId, packet->GetDestinationService(), NOTICE, 5);
        stringstream out;

        out << ID << "," << Service << "|";
        notice->SetLastHop(out.str());
        notice->SetOriginSourceSeqNum(packet->GetSeqNum());

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
    //Boradcast
    if(packet->GetDestination() == 255)
    {
        int n = gateSize("g$o");
        int outGateBaseId = gateBaseId("g$o");
        int senderIndex = packet->getArrivalGate() != NULL ? packet->getArrivalGate()->getIndex() : -1;

        for (int i=0; i<n; i++)
        {
            if( i == senderIndex) continue;
            send(i==n-1 ? packet : packet->dup(), outGateBaseId+i);
        }
    }
    else
    {
        int gateId = routingTable.FindPath(packet->GetDestination());
        if(gateId == -1)
        {
            int n = gateSize("g");
            int outGateBaseId = gateBaseId("g$o");
            for (int i=0; i<n; i++)
               send(i==n-1 ? packet : packet->dup(), outGateBaseId+i);
        }
        else
        {
            //When this table has corresponding routing entry
            send(packet, gateId);
        }
    }
}
