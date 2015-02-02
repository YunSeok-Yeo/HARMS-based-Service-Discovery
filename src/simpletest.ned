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
network Simpletest
{
    submodules:
        PortableDevice0: PortableDevice {
            @display("p=379,506");
        }
        PortableDevice1: PortableDevice {
            @display("p=523,506");
        }
        PortableDevice2: PortableDevice {
            @display("p=535,378");
        }
        PortableDevice3: PortableDevice {
            @display("p=291,565");
        }
        PortableDevice4: PortableDevice {
            @display("p=496,248");
        }
        PortableDevice5: PortableDevice {
            @display("p=192,272");
        }
        PortableDevice6: PortableDevice {
            @display("p=79,248");
        }
        PortableDevice7: PortableDevice {
            @display("p=118,393");
        }
        PortableDevice8: PortableDevice {
            @display("p=347,265");
        }
        PortableDevice9: PortableDevice {
            @display("p=146,532");
        }
    connections:
        PortableDevice0.g++ <--> Link <--> PortableDevice1.g++;
        PortableDevice0.g++ <--> Link <--> PortableDevice3.g++;
        PortableDevice1.g++ <--> Link <--> PortableDevice2.g++;
        PortableDevice2.g++ <--> Link <--> PortableDevice4.g++;
        PortableDevice3.g++ <--> Link <--> PortableDevice9.g++;
        PortableDevice5.g++ <--> Link <--> PortableDevice8.g++;
        PortableDevice4.g++ <--> Link <--> PortableDevice8.g++;
        PortableDevice9.g++ <--> Link <--> PortableDevice7.g++;
        PortableDevice5.g++ <--> Link <--> PortableDevice7.g++;
        PortableDevice7.g++ <--> Link <--> PortableDevice6.g++;
}
