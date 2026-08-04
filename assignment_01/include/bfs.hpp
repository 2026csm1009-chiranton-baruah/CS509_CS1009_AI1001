#ifndef BFS_HPP
#define BFS_HPP

#include "graph.hpp"

#include <vector>

std::vector<int> BFS(
    const CSRGraph& graph,
    int source,
    std::vector<int>& distance);

#endif
