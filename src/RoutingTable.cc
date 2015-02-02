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

#include <RoutingTable.h>
RoutingTable::RoutingTable() {
    // TODO Auto-generated constructor stub

}

RoutingTable::~RoutingTable() {
    // TODO Auto-generated destructor stub
    int len = table.size();
    for(int i = 0; i < len; i++){
        delete table[i];
    }
    table.clear();
}

// Compare with old path and Update entry
void RoutingTable::UpdateEntry(int destinationId, int nextHop, int hopCount){
    int len = table.size();
    RoutingEntry *e;
    for(int i = 0; i < len; i++){
        e = table[i];
        if(e->destinationId == destinationId){
            if(e->hopCount > hopCount){
                e->nextHop = nextHop;
                e->hopCount = hopCount;
            }
            return;
        }
    }
    e = new RoutingEntry;
    e->destinationId = destinationId;
    e->nextHop = nextHop;
    e->hopCount = hopCount;
    table.push_back(e);
}

int RoutingTable::GetTableSize(){
    return table.size();
}



/*
 *  Find entry that has destination
 *  Return next gateId
 */
int RoutingTable::FindPath(int destination){
    int len = table.size();
    RoutingEntry *e;
    for(int i = 0; i < len; i++){
        e = table[i];
        if(e->destinationId == destination){
            return e->nextHop;
        }
    }
    return -1;
}
