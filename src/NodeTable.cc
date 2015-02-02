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

#include <NodeTable.h>

NodeTable::NodeTable() {
    // TODO Auto-generated constructor stub
}

NodeTable::~NodeTable() {
    // TODO Auto-generated destructor stub
    int len = table.size();
    for(int i = 0; i < len; i++){
        delete table[i];
    }
    table.clear();
}

void NodeTable::UpdateEntry(int nodeId, int nodeService, int nodeLocation, int nodeLifeTime){
    int len = table.size();
    NodeEntry *e;
    for( int i = 0 ; i < len ; i++ ){
        e = table[i];
        if(e->nodeId == nodeId/* && e->GetNodeLocation() == location*/){
            e->nodeService = nodeService;
            e->nodeLifeTime = nodeLifeTime;
            e->nodeLocation = nodeLocation;
            return;
        }
    }
    e = new NodeEntry;
    e->nodeId = nodeId;
    e->nodeService = nodeService;
    e->nodeLifeTime = nodeLifeTime;
    e->nodeLocation = nodeLocation;

    table.push_back(e);
}


int NodeTable::GetTableSize(){
    return table.size();
}

/*
 *  Return suitable Service provider Id
 */
int NodeTable::FindService(int service){
    int len = table.size();
    NodeEntry *e;
    for( int i = 0 ; i < len ; i++ ){
        e = table[i];
        if(e->nodeService == service/* && e->GetNodeLocation() == location*/){
            return e->nodeId;
        }
    }
    return -1;
}
