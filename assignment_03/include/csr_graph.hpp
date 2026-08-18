#ifndef CSR_GRAPH_HPP
#define CSR_GRAPH_HPP

#include <vector>
#include <utility>

struct CSRGraph {
    int V;
    std::vector<int> row_ptr;
    std::vector<int> col_idx;
    std::vector<int> values;
};

inline CSRGraph convertToCSR(
    const std::vector<std::vector<std::pair<int, int>>>& adj
) {
    int V = static_cast<int>(adj.size());

    CSRGraph g;
    g.V = V;
    g.row_ptr.resize(V + 1, 0);

    int edgeCount = 0;
    for (int u = 0; u < V; ++u) {
        g.row_ptr[u] = edgeCount;
        edgeCount += static_cast<int>(adj[u].size());
    }
    g.row_ptr[V] = edgeCount;

    g.col_idx.reserve(edgeCount);
    g.values.reserve(edgeCount);

    for (int u = 0; u < V; ++u) {
        for (const auto& edge : adj[u]) {
            g.col_idx.push_back(edge.first);
            g.values.push_back(edge.second);
        }
    }

    return g;
}

#endif
