#include "../include/sssp.hpp"

#include <queue>
#include <limits>
#include <functional>

std::vector<int> Dijkstra(
    const CSRGraph& graph,
    int source)
{
    const int INF = std::numeric_limits<int>::max();

    std::vector<int> distance(graph.vertices, INF);

    using Node = std::pair<int, int>;
    // (distance, vertex)

    std::priority_queue<
        Node,
        std::vector<Node>,
        std::greater<Node>
    > pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;

        pq.pop();

        if (currentDistance > distance[currentVertex])
            continue;

        for (int i = graph.row_ptr[currentVertex];
             i < graph.row_ptr[currentVertex + 1];
             ++i)
        {
            int neighbour = graph.col_idx[i];
            int weight = graph.values[i];

            if (distance[currentVertex] + weight <
                distance[neighbour])
            {
                distance[neighbour] =
                    distance[currentVertex] + weight;

                pq.push(
                    {distance[neighbour], neighbour});
            }
        }
    }

    return distance;
}
