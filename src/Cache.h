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

#ifndef CACHE_H_
#define CACHE_H_

#include <vector>

using namespace std;
class Cache {
    struct cacheEntry{
        int sourceId;
        int seqNum;
    };
    vector<cacheEntry *> cache;
public:
    Cache();
    virtual ~Cache();
    void AddEntry(int sourceId, int seqNum);
    bool checkEntry(int sourceId, int seqNum);
};

#endif /* CACHE_H_ */
