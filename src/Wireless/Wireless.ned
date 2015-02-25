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

package servicediscovery.Wireless;

//
// TODO auto-generated module
//

import inet.world.radio.ChannelControl;


simple Wireless
{
    parameters:
        int localSAP = default(0xf0);
        int remoteSAP = default(0xf1);
        volatile int reqLength @unit(B) = default(100B);  // length of request packets
        volatile int respLength @unit(B) = default(1KiB);  // length of response packets
    gates:
        input in @labels(Ieee802Ctrl/up);
        output out @labels(Ieee802Ctrl/down);

}

network WirelessNetwork
{
    parameters:
        int numCli;
        @display("b=297,203");
    submodules:
        cliHost[numCli]: WifiNode {
            parameters:
                @display("r=,,#707070");
        }
        channelControl: ChannelControl {
            parameters:
                @display("p=61,46");
        }
}
