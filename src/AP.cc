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

#include "AP.h"

Define_Module(AP);

void AP::initialize()
{
    PortableDevice::initialize();
    Service = APSERVICE;
    DNS = -1;
}

void AP::handleMessage(cMessage *msg)
{
    PortableDevice::handleMessage(msg);
}
void AP::Query(CustomPacket *packet){
    int targetId;
    if((targetId = nodeTable.FindService(packet->GetDestinationService())) != -1){
        CustomPacket *reply = GeneratePacket("reply", packet->GetSource(), 0, REPLY, packet->GetHopCount());
        stringstream out;

        out << targetId << "," << packet->GetDestinationService() << "|"; //To reach destination service, Source should send packet to this node.
        reply->SetLastHop(out.str());

        forwardMessage(reply);
        delete packet;
    }else{
        if(DNS == -1)
            DNS = nodeTable.FindService(DNSSERVICE);
        packet->SetDestination(DNS);
        forwardMessage(packet);
    }
}
void AP::Register(CustomPacket *packet){
    CustomPacket *reply = GeneratePacket("reply", packet->GetSource(), 0, REPLY, packet->GetHopCount());
    stringstream out;

    out << ID << "," << packet->GetDestinationService() << "|"; //To reach destination service, Source should send packet to this node.
    reply->SetLastHop(out.str());

    forwardMessage(reply);
    if(DNS == -1)
        DNS = nodeTable.FindService(DNSSERVICE);
    packet->SetDestination(DNS);
    forwardMessage(packet);
    //delete packet;
}
