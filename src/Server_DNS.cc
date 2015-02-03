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

#include "Server_DNS.h"

Define_Module(Server_DNS);

void Server_DNS::initialize()
{
    // TODO - Generated method body
    ID = getId();
    seqNum = 0;
    Service = DNSSERVICE;
}

void Server_DNS::handleMessage(cMessage *msg)
{
    CustomPacket *packet = check_and_cast<CustomPacket *>(msg);

    switch(packet->GetType()){
    case HELLO:
        Hello(packet);
    case QUERY:
        Query(packet);
        break;
    case REGISTER:
        Register(packet);
        break;
    }
    // TODO - Generated method body
}
CustomPacket* Server_DNS::GeneratePacket(const char* name, int destinationId, int destinationService, int type, int maxHopCount){

    CustomPacket *newPacket = new CustomPacket(name);
    newPacket->SetDestination(destinationId);
    newPacket->SetDestinationService(destinationService);
    newPacket->SetSource(ID);
    newPacket->SetSeqNum(seqNum++);
    newPacket->SetType(type);
    newPacket->SetMaxHopCount(maxHopCount);

    return newPacket;
}
void Server_DNS::Hello(CustomPacket *packet){
    CustomPacket *reply = GeneratePacket("reply", packet->GetSource(), 0, REPLY, packet->GetHopCount() + 1);
    stringstream out;

    out << ID << "," << Service << "|"; //To reach destination service, Source should send packet to this node.
    reply->SetLastHop(out.str());

    int outGateId = gateBaseId("g$o") + packet->getArrivalGate()->getIndex();
    send(reply, outGateId);
}
void Server_DNS::Query(CustomPacket *packet){
    int targetId;
    if((targetId = nodeTable.FindService(packet->GetDestinationService())) != -1){
        CustomPacket *reply = GeneratePacket("reply", packet->GetSource(), 0, REPLY, packet->GetHopCount() + 1);
        stringstream out;

        out << targetId << "," << packet->GetDestinationService() << "|"; //To reach destination service, Source should send packet to this node.
        reply->SetLastHop(out.str());

        int outGateId = gateBaseId("g$o") + packet->getArrivalGate()->getIndex();
        send(reply, outGateId);
    }
    delete packet;
}

void Server_DNS::Register(CustomPacket *packet){
    string lastHop = packet->GetLastHop();
    string token, secondToken;
    size_t pos, secondPos;
    string delimiter = "|", secondDelimiter = ",";
    if((pos = lastHop.find(delimiter)) != string::npos){
        token = lastHop.substr(0, pos);

        secondPos = token.find(secondDelimiter);
        secondToken = token.substr(0, secondPos);

        int id = atoi(secondToken.c_str());

        token.erase(0, secondPos + secondDelimiter.length());
        nodeTable.UpdateEntry(id, atoi(token.c_str()), 0, 10);

        lastHop.erase(0, pos + delimiter.length());
    }
    delete packet;
    /*
    while ((pos = lastHop.find(delimiter)) != string::npos) {

        token = lastHop.substr(0, pos);

        secondPos = token.find(secondDelimiter);
        secondToken = token.substr(0, secondPos);

        int id = atoi(secondToken.c_str());

        token.erase(0, secondPos + secondDelimiter.length());
        nodeTable.UpdateEntry(id, atoi(token.c_str()), 0, 10);

        lastHop.erase(0, pos + delimiter.length());
    }
    */
}
