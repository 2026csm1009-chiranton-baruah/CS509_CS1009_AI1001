#ifndef GRAPH_IO_HPP
#define GRAPH_IO_HPP

#include <string>
#include "graph.hpp"

bool loadUnweightedGraph(
    const std::string& filename,
    AdjacencyList& graph,
    int& source,
    int& vertices,
    int& edges);

bool loadWeightedGraph(
    const std::string& filename,
    AdjacencyList& graph,
    int& source,
    int& vertices,
    int& edges);

#endif
