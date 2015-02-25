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

#include "APCli.h"
#include <string>
#include <string.h>

Define_Module(APCli);
using namespace std;

void APCli::initialize()
{
    ID = getId();
    Service = APSERVICE;

    Location = par("location");

    for(int i = 0; i < SERVICENUM ; i++){
        ServiceArray[i] = 0;
    }

    UpdateDisplay();
}

void APCli::handleMessage(cMessage *msg)
{
    //According to receiver gate, change method
    //EV << "sibong\t" << msg->getArrivalGate()->getBaseName() << endl;

    if(strcmp(msg->getArrivalGate()->getBaseName(), "in") == 0)
    {
        PortableDevice::handleMessage(msg);
    }
    else
    {
        CustomPacket *packet = check_and_cast<CustomPacket *>(msg);
        stringstream out;
        out << packet->GetLastHop() << ID << "," << Service << "|";
        packet->SetLastHop(out.str());

        forwardMessage(packet);
    }
}

void APCli::Query(CustomPacket *packet){
    int targetId;
    if((targetId = nodeTable.FindService(packet->GetDestinationService())) != -1){
        CustomPacket *reply = GeneratePacket("reply", packet->GetSource(), 0, REPLY, packet->GetHopCount());
        stringstream out;

        out << targetId << "," << packet->GetDestinationService() << "|"; //To reach destination service, Source should send packet to this node.
        reply->SetLastHop(out.str());
        reply->setKind(2);

        forwardMessage(reply);
        delete packet;
    }else{
        /*if(DNS == -1)
            DNS = nodeTable.FindService(DNSSERVICE);
        packet->SetDestination(DNS);
        forwardMessage(packet);*/
        send(packet, "g$o");
    }
}
void APCli::Register(CustomPacket *packet){
    CustomPacket *reply = GeneratePacket("reply", packet->GetSource(), 0, REPLY, packet->GetHopCount());
    stringstream out;

    out << ID << "," << packet->GetDestinationService() << "|"; //To reach destination service, Source should send packet to this node.
    reply->SetLastHop(out.str());
    reply->setKind(1);
    forwardMessage(reply);


    //Get Source service number
    string lastHop = packet->GetLastHop();
    int Service = atoi(lastHop.substr(lastHop.find(",") + 1, lastHop.find("|") - lastHop.find(",") - 1).c_str());

    if(ServiceArray[Service] > 0)
        EV << "AP already has service(" << Service << ")" << "\n";
    else
        EV << "AP send register packet for service(" << Service << ")" << "\n";
    ServiceArray[Service]++;


    //If target service provider is only one, then forward message to server to register.
    if(ServiceArray[Service] == 1){
        send(packet, "g$o");
        /*packet->SetDestination(DNS);
        packet->SetLocation(Location);

        forwardMessage(packet);*/
    }else{
        delete packet;
    }
}
