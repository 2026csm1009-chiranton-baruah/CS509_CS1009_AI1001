#include "algorithms.hpp"
#include <algorithm>
#include <array>
#include <queue>
#include <stack>

namespace {
inline bool has_edge(const CSRGraph& g, int u, int v) {
    const auto b = g.col_idx.begin() + g.row_ptr[u];
    const auto e = g.col_idx.begin() + g.row_ptr[u + 1];
    return std::binary_search(b, e, v);
}
}

long long triangle_count(const CSRGraph& g, std::vector<std::array<int,3>>* triangles) {
    long long raw = 0;
    if (triangles) triangles->clear();
    for (int u = 0; u < g.vertices; ++u) {
        for (int p = g.row_ptr[u]; p < g.row_ptr[u + 1]; ++p) {
            int v = g.col_idx[p];
            if (v <= u) continue;
            const int lo = p + 1;
            for (int q = lo; q < g.row_ptr[u + 1]; ++q) {
                int w = g.col_idx[q];
                if (w <= v) continue;
                if (has_edge(g, v, w)) {
                    ++raw;
                    if (triangles) triangles->push_back({u, v, w});
                }
            }
        }
    }
    return raw;
}

std::vector<double> betweenness_centrality(const CSRGraph& g) {
    const int n = g.vertices;
    std::vector<double> cb(n, 0.0), delta(n);
    std::vector<int> dist(n), queue_buf(n);
    std::vector<std::vector<int>> pred(n);
    std::vector<double> sigma(n);
    std::vector<int> stack;
    stack.reserve(n);
    for (int s = 0; s < n; ++s) {
        std::fill(dist.begin(), dist.end(), -1);
        std::fill(sigma.begin(), sigma.end(), 0.0);
        for (auto& p : pred) p.clear();
        std::fill(delta.begin(), delta.end(), 0.0);
        stack.clear();
        int qh = 0, qt = 0;
        queue_buf[qt++] = s;
        dist[s] = 0;
        sigma[s] = 1.0;
        while (qh < qt) {
            int v = queue_buf[qh++];
            stack.push_back(v);
            for (int p = g.row_ptr[v]; p < g.row_ptr[v + 1]; ++p) {
                int w = g.col_idx[p];
                if (dist[w] < 0) {
                    dist[w] = dist[v] + 1;
                    queue_buf[qt++] = w;
                }
                if (dist[w] == dist[v] + 1) {
                    sigma[w] += sigma[v];
                    pred[w].push_back(v);
                }
            }
        }
        while (!stack.empty()) {
            int w = stack.back(); stack.pop_back();
            for (int v : pred[w]) {
                if (sigma[w] != 0.0)
                    delta[v] += (sigma[v] / sigma[w]) * (1.0 + delta[w]);
            }
            if (w != s) cb[w] += delta[w];
        }
    }
    return cb;
}

std::vector<int> connected_components(const CSRGraph& g, int& component_count) {
    const int n = g.vertices;
    std::vector<int> comp(n, -1), q(n);
    component_count = 0;
    for (int s = 0; s < n; ++s) {
        if (comp[s] != -1) continue;
        int head = 0, tail = 0;
        q[tail++] = s;
        comp[s] = component_count;
        while (head < tail) {
            int u = q[head++];
            for (int p = g.row_ptr[u]; p < g.row_ptr[u + 1]; ++p) {
                int v = g.col_idx[p];
                if (comp[v] == -1) {
                    comp[v] = component_count;
                    q[tail++] = v;
                }
            }
        }
        ++component_count;
    }
    return comp;
}
