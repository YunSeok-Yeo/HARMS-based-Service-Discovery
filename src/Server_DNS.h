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

#ifndef __SERVICEDISCOVERY_SERVER_DNS__H_
#define __SERVICEDISCOVERY_SERVER_DNS__H_

#include <omnetpp.h>
#include "CustomPacket.h"
#include "NodeTable.h"

/**
 * TODO - Generated class
 */
class Server_DNS : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    NodeTable nodeTable;
    //RoutingTable routingTable;
    virtual void Register(CustomPacket *packet);
    virtual void Query(CustomPacket *packet);
    virtual CustomPacket* GeneratePacket(const char* name, int destinationId, int destinationService, int type, int maxHopCount);
    int ID, seqNum, Service;
};

#endif
