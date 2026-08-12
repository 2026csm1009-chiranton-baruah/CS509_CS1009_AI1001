#pragma once
#include <cstddef>
#include <stdexcept>
#include <string>
#include <vector>

struct GraphInput {
    int vertices = 0;
    long long edges = 0;
    std::vector<std::vector<int>> adjacency;
};

struct CSRGraph {
    int vertices = 0;
    std::vector<int> row_ptr;
    std::vector<int> col_idx;
};

GraphInput read_undirected_adjacency_list(const std::string& path);
CSRGraph adjacency_list_to_csr(const GraphInput& graph);
void validate_undirected_graph(const GraphInput& graph);

inline int degree(const CSRGraph& g, int u) {
    return g.row_ptr[u + 1] - g.row_ptr[u];
}
