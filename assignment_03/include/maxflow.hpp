#ifndef MAXFLOW_HPP
#define MAXFLOW_HPP

#include "csr_graph.hpp"

#include <vector>

struct CutEdge {
    int from;
    int to;
    int capacity;
};

struct MaxflowResult {
    int max_flow;
    int cut_capacity;

    std::vector<bool> source_side;
    std::vector<CutEdge> cut_edges;
};

MaxflowResult maxflowMincut(
    const CSRGraph& graph,
    int source,
    int sink
);

#endif
