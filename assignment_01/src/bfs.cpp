#include "../include/bfs.hpp"

#include <queue>

std::vector<int> BFS(
    const CSRGraph& graph,
    int source,
    std::vector<int>& distance)
{
    std::vector<int> traversal;
    std::vector<bool> visited(graph.vertices, false);

    distance.assign(graph.vertices, -1);

    std::queue<int> q;

    visited[source] = true;
    distance[source] = 0;

    q.push(source);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        traversal.push_back(current);

        for (int i = graph.row_ptr[current];
             i < graph.row_ptr[current + 1];
             i++)
        {
            int neighbour = graph.col_idx[i];

            if (!visited[neighbour])
            {
                visited[neighbour] = true;

                distance[neighbour] =
                    distance[current] + 1;

                q.push(neighbour);
            }
        }
    }

    return traversal;
}
