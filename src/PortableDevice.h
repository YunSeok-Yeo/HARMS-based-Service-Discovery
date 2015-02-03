/*
 * PortableDevice.h
 *
 *  Created on: Feb 2, 2015
 *      Author: yys
 */

#ifndef PORTABLEDEVICE_H_
#define PORTABLEDEVICE_H_


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

#include <omnetpp.h>
#include <string>
#include <sstream>
#include "CustomPacket.h"
#include "NodeTable.h"
#include "RoutingTable.h"
#include "Cache.h"
#define SERVICENUM 10
/**
 * TODO - Generated class
 */
using namespace std;

class PortableDevice : public cSimpleModule
{
    protected:
        virtual void forwardMessage(CustomPacket *msg);
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        virtual void Reply(CustomPacket *packet);
        virtual void Query(CustomPacket *packet);
        virtual void Notice(CustomPacket *packet);
        virtual void Retransmit(CustomPacket *packet);
        virtual void Hello(CustomPacket *packet);
        virtual void Register(CustomPacket *packet);
        virtual CustomPacket* GeneratePacket(const char *name, int destinationId, int destinationService, int type, int maxHopCount);
        void UpdateTables(string lastHop, int gateId, int maxHopCount);
        int Service;
        int ID;
        CustomPacket *query, *timer1, *findAP, *timer2;
        NodeTable nodeTable;
        RoutingTable routingTable;
        Cache cache;
        int seqNum;
        int currentState;
};





#endif /* PORTABLEDEVICE_H_ */
