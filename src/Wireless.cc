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

#include "Wireless.h"
#include <string>
Define_Module(Wireless);

using namespace std;
void Wireless::initialize()
{
    // TODO - Generated method body
    string list[7];
    list[0] = "Wireless0";
    list[1] = "Wireless1";
    list[2] = "Wireless2";
    list[3] = "Wireless3";
    list[4] = "Wireless4";
    list[5] = "Wireless5";
    list[6] = "Wireless6";
    cMessage *msg = new cPacket("hello");
    cModule *targetModule = getParentModule()->getSubmodule(list[intuniform(0, 6)].c_str());
    sendDirect(msg, 10, 10, targetModule, "radioIn");
    //sendDirect(msg, targetModule, "radioIn");
}

void Wireless::handleMessage(cMessage *msg)
{
    delete msg;
    // TODO - Generated method body
}
