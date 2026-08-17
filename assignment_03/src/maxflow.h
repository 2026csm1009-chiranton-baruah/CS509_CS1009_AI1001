#ifndef MAXFLOW_H
#define MAXFLOW_H

#include <vector>

using namespace std;

struct CutEdge
{
    int u;
    int v;
    int cap;
};

struct FlowResult
{
    int maxFlow;
    vector<int> sourceSide;
    vector<int> sinkSide;
    vector<CutEdge> cutEdges;
};

FlowResult maxFlow(
    const vector<vector<int>>& graph,
    const vector<vector<int>>& capacity,
    int source,
    int sink
);

#endif
