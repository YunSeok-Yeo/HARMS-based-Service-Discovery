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


#include <csimulation.h>
#include "EtherApp_m.h"
#include "Ieee802Ctrl_m.h"
#include <MACAddress.h>
#include "Wireless.h"


//#include <string>

Define_Module(Wireless);

simsignal_t Wireless::sentPkSignal = registerSignal("sentPk");
simsignal_t Wireless::rcvdPkSignal = registerSignal("rcvdPk");

using namespace std;
void Wireless::initialize()
{
    // TODO - Generated method body

    cMessage *timer = new cPacket("timer");

    scheduleAt(intuniform(5, 10), timer);
}

void Wireless::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage()){
        MACAddress destMACAddress;
        int localSAP = par("localSAP");
        int remoteSAP = par("remoteSAP");
        int seqNum = 0;
        cPar *reqLength = &par("reqLength");
        cPar *respLength = &par("respLength");

        cModule *destMAC =
                getParentModule()->getParentModule()->getSubmodule("cliHost", intuniform(0, 5))->getSubmodule("wlan")->getSubmodule("mac");
        if (!destMAC)
        {
            error("module 'error' has no 'mac' submodule");
        }//destMAC->par("address")
        destMACAddress.setBroadcast();
        Ieee802Ctrl *etherctrl = new Ieee802Ctrl();
        etherctrl->setSsap(localSAP);
        etherctrl->setDsap(remoteSAP);
        etherctrl->setDest(destMACAddress);

        EtherAppReq *datapacket = new EtherAppReq("text", IEEE802CTRL_DATA);

        datapacket->setRequestId(seqNum);

        long len = reqLength->longValue();
        datapacket->setByteLength(len);

        long respLen = respLength->longValue();
        datapacket->setResponseBytes(respLen);


        datapacket->setControlInfo(etherctrl);
        emit(sentPkSignal, datapacket);

        EV << "sending packet `" << datapacket->getName() << " to " << destMACAddress << "'\n";
        send(datapacket, "out");
        delete msg;
    }else
        receivePacket(check_and_cast<cPacket*>(msg));
    // TODO - Generated method body
}

void Wireless::receivePacket(cPacket *msg)
{
    EV << "Received packet `" << msg->getName() << "'\n";

    emit(rcvdPkSignal, msg);
    delete msg;
}
