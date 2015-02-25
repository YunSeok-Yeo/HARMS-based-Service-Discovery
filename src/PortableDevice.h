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
#include <MACAddress.h>
#include "CustomPacket.h"
#include "NodeTable.h"
#include "CustomRoutingTable.h"
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
        virtual void UpdateDisplay();
        virtual CustomPacket* GeneratePacket(const char *name, int destinationId, int destinationService, int type, int maxHopCount);
        void UpdateTables(string lastHop, string macAddress, int maxHopCount);
        void UpdateNodeTable(string nodeInfo);
        void UpdateRoutingTable(string routingInfo, string macAddress);
        int Service;
        int ID;
        MACAddress MacAddress;
        CustomPacket *hello, *query, *nodeRegister, *helloTimer, *queryTimer, *registerTimer;
        NodeTable nodeTable;
        CustomRoutingTable routingTable;
        Cache cache;
        int seqNum;
        int currentState;
        static simsignal_t sentPkSignal;
        static simsignal_t rcvdPkSignal;
};





#endif /* PORTABLEDEVICE_H_ */
