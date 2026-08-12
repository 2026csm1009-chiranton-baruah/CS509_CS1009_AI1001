#pragma once
#include "graph.hpp"
#include <array>
#include <vector>

long long triangle_count(const CSRGraph& graph, std::vector<std::array<int,3>>* triangles = nullptr);
std::vector<double> betweenness_centrality(const CSRGraph& graph);
std::vector<int> connected_components(const CSRGraph& graph, int& component_count);
