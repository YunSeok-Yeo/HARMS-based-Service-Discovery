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

#include <Cache.h>

Cache::Cache() {
    // TODO Auto-generated constructor stub
}

Cache::~Cache() {
    // TODO Auto-generated destructor stub
    int len = cache.size();
    for(int i = 0; i < len; i++){
        delete cache[i];
    }
    cache.clear();
}

void Cache::AddEntry(int sourceId, int seqNum){
    cacheEntry *e = new cacheEntry;
    e->seqNum = seqNum;
    e->sourceId = sourceId;
    cache.push_back(e);
}
bool Cache::checkEntry(int sourceId, int seqNum){
    int len = cache.size();
    cacheEntry *e;
    for(int i = 0; i < len; i++){
        e = cache[i];
        if(e->sourceId == sourceId && e->seqNum == seqNum){
            return true;
        }
    }
    return false;
}
