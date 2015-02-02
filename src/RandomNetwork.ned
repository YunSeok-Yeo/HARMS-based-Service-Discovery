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
// Generated network with random topology (50 PortableDevices, 80 edges, seed=8765).
//
network RandomNetwork {
    submodules:
        PortableDevice0 : PortableDevice;
        PortableDevice1 : PortableDevice;
        PortableDevice2 : PortableDevice;
        PortableDevice3 : PortableDevice;
        PortableDevice4 : PortableDevice;
        PortableDevice5 : PortableDevice;
        PortableDevice6 : PortableDevice;
        PortableDevice7 : PortableDevice;
        PortableDevice8 : PortableDevice;
        PortableDevice9 : PortableDevice;
        PortableDevice10 : PortableDevice;
        PortableDevice11 : PortableDevice;
        PortableDevice12 : PortableDevice;
        PortableDevice13 : PortableDevice;
        PortableDevice14 : PortableDevice;
        PortableDevice15 : PortableDevice;
        PortableDevice16 : PortableDevice;
        PortableDevice17 : PortableDevice;
        PortableDevice18 : PortableDevice;
        PortableDevice19 : PortableDevice;
        PortableDevice20 : PortableDevice;
        PortableDevice21 : PortableDevice;
        PortableDevice22 : PortableDevice;
        PortableDevice23 : PortableDevice;
        PortableDevice24 : PortableDevice;
        PortableDevice25 : PortableDevice;
        PortableDevice26 : PortableDevice;
        PortableDevice27 : PortableDevice;
        PortableDevice28 : PortableDevice;
        PortableDevice29 : PortableDevice;
        PortableDevice30 : PortableDevice;
        PortableDevice31 : PortableDevice;
        PortableDevice32 : PortableDevice;
        PortableDevice33 : PortableDevice;
        PortableDevice34 : PortableDevice;
        PortableDevice35 : PortableDevice;
        PortableDevice36 : PortableDevice;
        PortableDevice37 : PortableDevice;
        PortableDevice38 : PortableDevice;
        PortableDevice39 : PortableDevice;
        PortableDevice40 : PortableDevice;
        PortableDevice41 : PortableDevice;
        PortableDevice42 : PortableDevice;
        PortableDevice43 : PortableDevice;
        PortableDevice44 : PortableDevice;
        PortableDevice45 : PortableDevice;
        PortableDevice46 : PortableDevice;
        PortableDevice47 : PortableDevice;
        PortableDevice48 : PortableDevice;
        PortableDevice49 : PortableDevice;
    connections:
        PortableDevice0.g++ <--> Link <--> PortableDevice1.g++;
        PortableDevice0.g++ <--> Link <--> PortableDevice2.g++;
        PortableDevice0.g++ <--> Link <--> PortableDevice3.g++;
        PortableDevice0.g++ <--> Link <--> PortableDevice5.g++;
        PortableDevice1.g++ <--> Link <--> PortableDevice3.g++;
        PortableDevice1.g++ <--> Link <--> PortableDevice22.g++;
        PortableDevice1.g++ <--> Link <--> PortableDevice8.g++;
        PortableDevice1.g++ <--> Link <--> PortableDevice26.g++;
        PortableDevice2.g++ <--> Link <--> PortableDevice19.g++;
        PortableDevice2.g++ <--> Link <--> PortableDevice4.g++;
        PortableDevice2.g++ <--> Link <--> PortableDevice12.g++;
        PortableDevice2.g++ <--> Link <--> PortableDevice15.g++;
        PortableDevice3.g++ <--> Link <--> PortableDevice36.g++;
        PortableDevice3.g++ <--> Link <--> PortableDevice10.g++;
        PortableDevice3.g++ <--> Link <--> PortableDevice13.g++;
        PortableDevice3.g++ <--> Link <--> PortableDevice14.g++;
        PortableDevice4.g++ <--> Link <--> PortableDevice17.g++;
        PortableDevice4.g++ <--> Link <--> PortableDevice7.g++;
        PortableDevice4.g++ <--> Link <--> PortableDevice41.g++;
        PortableDevice5.g++ <--> Link <--> PortableDevice6.g++;
        PortableDevice5.g++ <--> Link <--> PortableDevice9.g++;
        PortableDevice6.g++ <--> Link <--> PortableDevice35.g++;
        PortableDevice6.g++ <--> Link <--> PortableDevice28.g++;
        PortableDevice6.g++ <--> Link <--> PortableDevice47.g++;
        PortableDevice7.g++ <--> Link <--> PortableDevice32.g++;
        PortableDevice7.g++ <--> Link <--> PortableDevice39.g++;
        PortableDevice7.g++ <--> Link <--> PortableDevice43.g++;
        PortableDevice7.g++ <--> Link <--> PortableDevice13.g++;
        PortableDevice8.g++ <--> Link <--> PortableDevice22.g++;
        PortableDevice8.g++ <--> Link <--> PortableDevice24.g++;
        PortableDevice8.g++ <--> Link <--> PortableDevice11.g++;
        PortableDevice8.g++ <--> Link <--> PortableDevice44.g++;
        PortableDevice9.g++ <--> Link <--> PortableDevice26.g++;
        PortableDevice10.g++ <--> Link <--> PortableDevice32.g++;
        PortableDevice10.g++ <--> Link <--> PortableDevice25.g++;
        PortableDevice10.g++ <--> Link <--> PortableDevice26.g++;
        PortableDevice10.g++ <--> Link <--> PortableDevice15.g++;
        PortableDevice11.g++ <--> Link <--> PortableDevice16.g++;
        PortableDevice11.g++ <--> Link <--> PortableDevice23.g++;
        PortableDevice11.g++ <--> Link <--> PortableDevice29.g++;
        PortableDevice11.g++ <--> Link <--> PortableDevice30.g++;
        PortableDevice12.g++ <--> Link <--> PortableDevice33.g++;
        PortableDevice12.g++ <--> Link <--> PortableDevice25.g++;
        PortableDevice13.g++ <--> Link <--> PortableDevice21.g++;
        PortableDevice14.g++ <--> Link <--> PortableDevice34.g++;
        PortableDevice14.g++ <--> Link <--> PortableDevice48.g++;
        PortableDevice14.g++ <--> Link <--> PortableDevice29.g++;
        PortableDevice14.g++ <--> Link <--> PortableDevice46.g++;
        PortableDevice14.g++ <--> Link <--> PortableDevice28.g++;
        PortableDevice14.g++ <--> Link <--> PortableDevice45.g++;
        PortableDevice16.g++ <--> Link <--> PortableDevice18.g++;
        PortableDevice16.g++ <--> Link <--> PortableDevice40.g++;
        PortableDevice16.g++ <--> Link <--> PortableDevice28.g++;
        PortableDevice17.g++ <--> Link <--> PortableDevice42.g++;
        PortableDevice17.g++ <--> Link <--> PortableDevice29.g++;
        PortableDevice18.g++ <--> Link <--> PortableDevice42.g++;
        PortableDevice18.g++ <--> Link <--> PortableDevice40.g++;
        PortableDevice19.g++ <--> Link <--> PortableDevice20.g++;
        PortableDevice19.g++ <--> Link <--> PortableDevice31.g++;
        PortableDevice21.g++ <--> Link <--> PortableDevice25.g++;
        PortableDevice21.g++ <--> Link <--> PortableDevice24.g++;
        PortableDevice21.g++ <--> Link <--> PortableDevice30.g++;
        PortableDevice22.g++ <--> Link <--> PortableDevice49.g++;
        PortableDevice23.g++ <--> Link <--> PortableDevice38.g++;
        PortableDevice23.g++ <--> Link <--> PortableDevice37.g++;
        PortableDevice23.g++ <--> Link <--> PortableDevice27.g++;
        PortableDevice24.g++ <--> Link <--> PortableDevice32.g++;
        PortableDevice24.g++ <--> Link <--> PortableDevice48.g++;
        PortableDevice24.g++ <--> Link <--> PortableDevice30.g++;
        PortableDevice26.g++ <--> Link <--> PortableDevice38.g++;
        PortableDevice26.g++ <--> Link <--> PortableDevice42.g++;
        PortableDevice26.g++ <--> Link <--> PortableDevice29.g++;
        PortableDevice26.g++ <--> Link <--> PortableDevice28.g++;
        PortableDevice28.g++ <--> Link <--> PortableDevice44.g++;
        PortableDevice31.g++ <--> Link <--> PortableDevice41.g++;
        PortableDevice33.g++ <--> Link <--> PortableDevice44.g++;
        PortableDevice34.g++ <--> Link <--> PortableDevice49.g++;
        PortableDevice35.g++ <--> Link <--> PortableDevice37.g++;
        PortableDevice37.g++ <--> Link <--> PortableDevice49.g++;
        PortableDevice39.g++ <--> Link <--> PortableDevice43.g++;
}
