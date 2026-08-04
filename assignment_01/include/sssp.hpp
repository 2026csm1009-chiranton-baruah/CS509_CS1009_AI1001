#ifndef SSSP_HPP
#define SSSP_HPP

#include "graph.hpp"

#include <vector>

std::vector<int> Dijkstra(
    const CSRGraph& graph,
    int source);

#endif
