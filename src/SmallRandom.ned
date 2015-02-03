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
// Generated network with random topology (15 PortableDevices, 18 edges, seed=100).
//
network Network
{
    parameters:
        int APs = 0;
    submodules:
        PortableDevice0: PortableDevice {
            @display("p=273,124");
        }
        PortableDevice1: PortableDevice {
            @display("p=235,248");
        }
        PortableDevice2: PortableDevice {
            @display("p=137,290");
        }
        PortableDevice3: PortableDevice {
            @display("p=359,367");
        }
        PortableDevice4: PortableDevice {
            @display("p=67,167");
        }
        PortableDevice5: PortableDevice {
            @display("p=234,400");
        }
        PortableDevice6: PortableDevice {
            @display("p=196,80");
        }
        PortableDevice7: PortableDevice {
            @display("p=387,181");
        }
        PortableDevice8: PortableDevice {
            @display("p=54,367");
        }
        PortableDevice9: PortableDevice {
            @display("p=510,235");
        }
        PortableDevice10: PortableDevice {
            @display("p=489,378");
        }
        PortableDevice11: PortableDevice {
            @display("p=437,63");
        }
        PortableDevice12: PortableDevice {
            @display("p=115,468");
        }
        PortableDevice13: PortableDevice {
            @display("p=61,47");
        }
        PortableDevice14: PortableDevice {
            @display("p=235,549");
        }
    connections:
        PortableDevice0.g++ <--> Link <--> PortableDevice1.g++;
        PortableDevice0.g++ <--> Link <--> PortableDevice4.g++;
        PortableDevice0.g++ <--> Link <--> PortableDevice6.g++;
        PortableDevice0.g++ <--> Link <--> PortableDevice11.g++;
        PortableDevice1.g++ <--> Link <--> PortableDevice2.g++;
        PortableDevice1.g++ <--> Link <--> PortableDevice3.g++;
        PortableDevice1.g++ <--> Link <--> PortableDevice5.g++;
        PortableDevice2.g++ <--> Link <--> PortableDevice4.g++;
        PortableDevice2.g++ <--> Link <--> PortableDevice8.g++;
        PortableDevice3.g++ <--> Link <--> PortableDevice7.g++;
        PortableDevice3.g++ <--> Link <--> PortableDevice10.g++;
        PortableDevice4.g++ <--> Link <--> PortableDevice8.g++;
        PortableDevice5.g++ <--> Link <--> PortableDevice8.g++;
        PortableDevice5.g++ <--> Link <--> PortableDevice12.g++;
        PortableDevice5.g++ <--> Link <--> PortableDevice14.g++;
        PortableDevice6.g++ <--> Link <--> PortableDevice13.g++;
        PortableDevice7.g++ <--> Link <--> PortableDevice9.g++;
        PortableDevice7.g++ <--> Link <--> PortableDevice11.g++;
}
