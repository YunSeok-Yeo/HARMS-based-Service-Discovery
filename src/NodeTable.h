/*
 * NodeTable.h
 *
 *  Created on: Jan 28, 2015
 *      Author: yys
 */

#ifndef NODETABLE_H_
#define NODETABLE_H_


#include <string>
#include <vector>
#define MAX_ITMES 100

using namespace std;
class NodeTable {

    struct NodeEntry{
        int nodeId;
        int nodeService;
        int nodeLocation;
        int nodeLifeTime;
    };
    vector<NodeEntry *> table;
public:
    NodeTable();
    virtual ~NodeTable();
    void UpdateEntry(int nodeId, int nodeService, int nodeLocation, int nodeLifeTime);
    int GetTableSize();
    int FindService(int service);
    string GetEntries();
};


#endif /* NODETABLE_H_ */
