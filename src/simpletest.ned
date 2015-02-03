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
// TODO auto-generated type
//

channel Link extends ned.DatarateChannel
{
    parameters:
        int cost = default(0);
        @display("ls=red,,d");
}

channel WiredLink extends ned.DatarateChannel
{
    parameters:
        int cost = default(0);
}
network Simpletest
{
    parameters:
        int APs = 2;
    submodules:
        Server: Server_DNS {

            @display("p=291,36");
        }
        AP1: AP {
            @display("p=157,127");
            location = 1;
        }
        AP2: AP {
            @display("p=414,133");
            location = 2;
        }
        PortableDevice0: PortableDevice {
            @display("p=433,330");
        }
        PortableDevice1: PortableDevice {
            @display("p=541,426");
        }
        PortableDevice2: PortableDevice {
            @display("p=568,312");
        }
        PortableDevice4: PortableDevice {
            @display("p=535,55");
        }
        PortableDevice8: PortableDevice {
            @display("p=414,206");
        }
        PortableDevice3: PortableDevice {
            @display("p=213,426");
        }
        PortableDevice5: PortableDevice {
            @display("p=213,228");
        }
        PortableDevice6: PortableDevice {
            @display("p=79,206");
        }
        PortableDevice7: PortableDevice {
            @display("p=135,322");
        }
        PortableDevice9: PortableDevice {
            @display("p=79,426");
        }
        PortableDevice10: PortableDevice {
            @display("p=96,22");
        }
    connections:
        PortableDevice0.g++ <--> Link <--> PortableDevice1.g++;
        PortableDevice0.g++ <--> Link <--> PortableDevice2.g++;
        PortableDevice0.g++ <--> Link <--> PortableDevice8.g++;
        PortableDevice1.g++ <--> Link <--> PortableDevice2.g++;
        PortableDevice3.g++ <--> Link <--> PortableDevice9.g++;
        PortableDevice3.g++ <--> Link <--> PortableDevice7.g++;
        PortableDevice9.g++ <--> Link <--> PortableDevice7.g++;
        PortableDevice5.g++ <--> Link <--> PortableDevice7.g++;
        PortableDevice7.g++ <--> Link <--> PortableDevice6.g++;
        PortableDevice10.g++ <--> Link <--> AP1.g++;
        AP2.g++ <--> Link <--> PortableDevice4.g++;
        AP2.g++ <--> Link <--> PortableDevice8.g++;
        AP1.g++ <--> WiredLink <--> AP2.g++;
        AP1.g++ <--> Link <--> PortableDevice5.g++;
        AP1.g++ <--> Link <--> PortableDevice6.g++;
        Server.g++ <--> WiredLink <--> AP1.g++;
        Server.g++ <--> WiredLink <--> AP2.g++;
}
