#include "../include/dfs.hpp"

#include <stack>

std::vector<int> DFS(
    const CSRGraph& graph,
    int source)
{
    std::vector<int> traversal;
    std::vector<bool> visited(graph.vertices, false);

    std::stack<int> stk;
    stk.push(source);

    while (!stk.empty())
    {
        int current = stk.top();
        stk.pop();

        if (visited[current])
            continue;

        visited[current] = true;
        traversal.push_back(current);

        /*
         * Push neighbours in reverse order.
         * This preserves the same traversal order
         * as a recursive DFS would.
         */
        for (int i = graph.row_ptr[current + 1] - 1;
             i >= graph.row_ptr[current];
             --i)
        {
            int neighbour = graph.col_idx[i];

            if (!visited[neighbour])
                stk.push(neighbour);
        }
    }

    return traversal;
}
