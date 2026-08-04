#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

struct Edge {
    int destination;
    int weight;

    Edge(int dest, int wt)
        : destination(dest), weight(wt) {}
};

struct CSRGraph {
    int vertices;
    int edges;

    std::vector<int> row_ptr;
    std::vector<int> col_idx;
    std::vector<int> values;

    CSRGraph()
        : vertices(0), edges(0) {}
};

using AdjacencyList = std::vector<std::vector<Edge>>;

#endif
