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

#ifndef ROUTINGTABLE_H_
#define ROUTINGTABLE_H_

#include <vector>
#define MAX_ITMES 100

using namespace std;
class RoutingTable {
    struct RoutingEntry{
        int destinationId;
        int nextHop;
        int hopCount;
    };
    vector<RoutingEntry *> table;
public:

    RoutingTable();
    virtual ~RoutingTable();

    void UpdateEntry(int destinationId, int nextHop, int hopCount);
    int GetTableSize();
    int FindPath(int destination);
};

#endif /* ROUTINGTABLE_H_ */
