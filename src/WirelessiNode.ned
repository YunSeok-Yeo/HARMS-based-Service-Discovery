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

import inet.base.NotificationBoard;
import inet.linklayer.ieee80211.Ieee80211Nic;
import inet.mobility.single.RandomWPMobility;


module WirelessNode
{
    parameters:
        @display("i=device/wifilaptop");
        @node();
    gates:
        input radioIn @directIn;

    submodules:
        notificationBoard: NotificationBoard {
            parameters:
                @display("p=52,70");
        }
        wlan: Ieee80211Nic {
            parameters:
                @display("p=112,134;q=queue");
                mgmtType = "Ieee80211MgmtAdhoc";
        }
        cli: PortableDevice {
            parameters:
                @display("b=40,24;p=180,60,col");
        }
        mobility: RandomWPMobility {
            parameters:
                @display("p=50,141");
        }
    connections allowunconnected:
        wlan.radioIn <-- radioIn;
        cli.out --> wlan.upperLayerIn;
        cli.in <-- wlan.upperLayerOut;
}
