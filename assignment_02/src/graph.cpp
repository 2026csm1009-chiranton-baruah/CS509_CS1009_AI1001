#include "graph.hpp"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unordered_map>

namespace {
struct PairHash {
    std::size_t operator()(const std::pair<int,int>& p) const noexcept {
        return (static_cast<std::size_t>(static_cast<unsigned int>(p.first)) << 32) ^
               static_cast<std::size_t>(static_cast<unsigned int>(p.second));
    }
};
}

void validate_undirected_graph(const GraphInput& graph) {
    if (graph.vertices < 0) throw std::runtime_error("Invalid vertex count");
    if (static_cast<int>(graph.adjacency.size()) != graph.vertices)
        throw std::runtime_error("Adjacency list vertex count mismatch");
    long long listed = 0;
    for (int u = 0; u < graph.vertices; ++u) {
        listed += static_cast<long long>(graph.adjacency[u].size());
        for (int v : graph.adjacency[u]) {
            if (v < 0 || v >= graph.vertices)
                throw std::runtime_error("Neighbor vertex out of range");
            if (v == u)
                throw std::runtime_error("Self-loops are not supported by this assignment");
        }
    }
    if (listed % 2 != 0)
        throw std::runtime_error("Undirected adjacency list must contain two entries per edge");
    if (listed / 2 != graph.edges)
        throw std::runtime_error("E does not match the adjacency list");
    for (int u = 0; u < graph.vertices; ++u) {
        for (int v : graph.adjacency[u]) {
            const auto& back = graph.adjacency[v];
            if (!std::binary_search(back.begin(), back.end(), u))
                throw std::runtime_error("Undirected edge is missing its reverse entry");
        }
    }
}

GraphInput read_undirected_adjacency_list(const std::string& path) {
    std::ifstream in(path);
    if (!in) throw std::runtime_error("Cannot open input file: " + path);
    GraphInput g;
    if (!(in >> g.vertices >> g.edges)) throw std::runtime_error("Invalid graph header");
    if (g.vertices < 0 || g.edges < 0) throw std::runtime_error("Negative V or E");
    g.adjacency.resize(g.vertices);
    for (int i = 0; i < g.vertices; ++i) {
        int u = -1, d = -1;
        if (!(in >> u >> d)) throw std::runtime_error("Missing vertex adjacency row");
        if (u != i) throw std::runtime_error("Vertex rows must be listed from 0 to V-1");
        if (d < 0) throw std::runtime_error("Negative degree");
        g.adjacency[u].resize(d);
        for (int j = 0; j < d; ++j) {
            if (!(in >> g.adjacency[u][j])) throw std::runtime_error("Missing neighbor");
        }
        std::sort(g.adjacency[u].begin(), g.adjacency[u].end());
        if (std::adjacent_find(g.adjacency[u].begin(), g.adjacency[u].end()) != g.adjacency[u].end())
            throw std::runtime_error("Duplicate neighbor in adjacency list");
    }
    validate_undirected_graph(g);
    return g;
}

CSRGraph adjacency_list_to_csr(const GraphInput& graph) {
    validate_undirected_graph(graph);
    CSRGraph csr;
    csr.vertices = graph.vertices;
    csr.row_ptr.resize(graph.vertices + 1, 0);
    for (int u = 0; u < graph.vertices; ++u)
        csr.row_ptr[u + 1] = csr.row_ptr[u] + static_cast<int>(graph.adjacency[u].size());
    csr.col_idx.resize(csr.row_ptr.back());
    for (int u = 0; u < graph.vertices; ++u)
        std::copy(graph.adjacency[u].begin(), graph.adjacency[u].end(), csr.col_idx.begin() + csr.row_ptr[u]);
    return csr;
}
