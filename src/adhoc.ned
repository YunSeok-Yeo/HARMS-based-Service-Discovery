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

package servicediscovery;

import inet.world.radio.ChannelControl;


network Adhoc
{
    parameters:
        int APs = 2;
    submodules:
        WirelessNode0: WirelessNode {
            @display("p=433,330");
        }
        WirelessNode1: WirelessNode {
            @display("p=541,426");
        }
        WirelessNode2: WirelessNode {
            @display("p=568,312");
        }
        WirelessNode4: WirelessNode {
            @display("p=535,55");
        }
        WirelessNode8: WirelessNode {
            @display("p=414,206");
        }
        WirelessNode3: WirelessNode {
            @display("p=213,426");
        }
        WirelessNode5: WirelessNode {
            @display("p=213,228");
        }
        WirelessNode6: WirelessNode {
            @display("p=79,206");
        }
        WirelessNode7: WirelessNode {
            @display("p=135,322");
        }
        WirelessNode9: WirelessNode {
            @display("p=79,426");
        }
        WirelessNode10: WirelessNode {
            @display("p=96,22");
        }
        channelControl: ChannelControl {
            parameters:
                @display("p=61,46");
        }
    connections allowunconnected:
}
