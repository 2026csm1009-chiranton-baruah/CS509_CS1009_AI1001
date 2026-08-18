#include "../include/maxflow.hpp"

#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

class Dinic {
private:

    struct Edge {
        int to;
        int reverse;
        int capacity;
    };

    std::vector<std::vector<Edge>> graph;
    std::vector<int> level;
    std::vector<int> current;

    bool bfs(int source, int sink) {

        std::fill(
            level.begin(),
            level.end(),
            -1
        );

        std::queue<int> q;

        level[source] = 0;
        q.push(source);

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            for (const Edge& edge : graph[u]) {

                if (edge.capacity > 0 &&
                    level[edge.to] == -1) {

                    level[edge.to] =
                        level[u] + 1;

                    q.push(edge.to);
                }
            }
        }

        return level[sink] != -1;
    }

    int dfs(
        int u,
        int sink,
        int flow
    ) {

        if (u == sink) {
            return flow;
        }

        for (int& i = current[u];
             i < static_cast<int>(graph[u].size());
             ++i) {

            Edge& edge = graph[u][i];

            if (edge.capacity <= 0) {
                continue;
            }

            if (level[edge.to] != level[u] + 1) {
                continue;
            }

            int pushed = dfs(
                edge.to,
                sink,
                std::min(flow, edge.capacity)
            );

            if (pushed > 0) {

                edge.capacity -= pushed;

                graph[edge.to][edge.reverse]
                    .capacity += pushed;

                return pushed;
            }
        }

        return 0;
    }

public:

    explicit Dinic(int vertices)
        : graph(vertices),
          level(vertices),
          current(vertices) {}

    void addEdge(
        int from,
        int to,
        int capacity
    ) {

        Edge forward{
            to,
            static_cast<int>(graph[to].size()),
            capacity
        };

        Edge reverse{
            from,
            static_cast<int>(graph[from].size()),
            0
        };

        graph[from].push_back(forward);
        graph[to].push_back(reverse);
    }

    int maxFlow(
        int source,
        int sink
    ) {

        int flow = 0;

        while (bfs(source, sink)) {

            std::fill(
                current.begin(),
                current.end(),
                0
            );

            while (true) {

                int pushed = dfs(
                    source,
                    sink,
                    std::numeric_limits<int>::max()
                );

                if (pushed == 0) {
                    break;
                }

                flow += pushed;
            }
        }

        return flow;
    }

    std::vector<bool> reachableFromSource(
        int source
    ) const {

        std::vector<bool> visited(
            graph.size(),
            false
        );

        std::queue<int> q;

        visited[source] = true;
        q.push(source);

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            for (const Edge& edge : graph[u]) {

                if (edge.capacity > 0 &&
                    !visited[edge.to]) {

                    visited[edge.to] = true;
                    q.push(edge.to);
                }
            }
        }

        return visited;
    }
};

MaxflowResult maxflowMincut(
    const CSRGraph& graph,
    int source,
    int sink
) {
    /*
     * IMPORTANT:
     *
     * This function receives the already-prepared CSR graph.
     * Residual-network construction therefore belongs inside
     * the timed Maxflow-Mincut algorithm call.
     */

    Dinic dinic(graph.V);

    for (int u = 0; u < graph.V; ++u) {

        for (int p = graph.row_ptr[u];
             p < graph.row_ptr[u + 1];
             ++p) {

            int v = graph.col_idx[p];
            int capacity = graph.values[p];

            dinic.addEdge(
                u,
                v,
                capacity
            );
        }
    }

    MaxflowResult result{};

    result.max_flow =
        dinic.maxFlow(source, sink);

    /*
     * The vertices reachable from the source
     * in the final residual graph form the
     * source side of the minimum cut.
     */
    result.source_side =
        dinic.reachableFromSource(source);

    result.cut_capacity = 0;

    /*
     * Determine the capacity of the original
     * edges crossing from S to T.
     *
     * The CSR graph still represents the original
     * graph, so it is used for cut-capacity calculation.
     */
    for (int u = 0; u < graph.V; ++u) {

        for (int p = graph.row_ptr[u];
             p < graph.row_ptr[u + 1];
             ++p) {

            int v = graph.col_idx[p];
            int capacity = graph.values[p];

            if (result.source_side[u] &&
                !result.source_side[v]) {

                result.cut_capacity += capacity;

                result.cut_edges.push_back(
                    {u, v, capacity}
                );
            }
        }
    }

    return result;
}
