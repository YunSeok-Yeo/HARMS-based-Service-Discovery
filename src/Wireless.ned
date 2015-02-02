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

//
// TODO auto-generated module
//
simple Wireless
{
    gates:
        input radioIn @directIn;

}

network WirelessNetwork
{
    submodules:
        Wireless0: Wireless {
            @display("p=216,456;i=device/wifilaptop;r=90");
        }
        Wireless1: Wireless {
            @display("p=389,463;i=device/wifilaptop;r=90");
        }
        Wireless2: Wireless {
            @display("p=389,287;i=device/wifilaptop;r=90");
        }
        Wireless3: Wireless {
            @display("p=204,304;i=device/wifilaptop;r=90");
        }
        Wireless4: Wireless {
            @display("p=396,193;i=device/wifilaptop;r=90");
        }
        Wireless5: Wireless {
            @display("p=216,183;i=device/wifilaptop;r=90");
        }
        Wireless6: Wireless {
            @display("p=79,248;i=device/wifilaptop;r=90");
        }
        Wireless7: Wireless {
            @display("p=48,343;i=device/wifilaptop;r=90");
        }
        Wireless8: Wireless {
            @display("p=300,256;i=device/wifilaptop;r=90");
        }
        Wireless9: Wireless {
            @display("p=79,432;i=device/wifilaptop;r=90");
        }
}
