#include "connected.h"
#include <queue>

using namespace std;

int connectedComponents(
    const vector<int>& offset,
    const vector<int>& edges,
    vector<int>& component
)
{
    int vertices = offset.size() - 1;

    vector<bool> visited(vertices, false);
    component.resize(vertices, -1);

    int count = 0;

    for (int start = 0; start < vertices; start++)
    {
        if (visited[start])
        {
            continue;
        }

        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            component[current] = count;

            for (int i = offset[current]; i < offset[current + 1]; i++)
            {
                int next = edges[i];

                if (!visited[next])
                {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        count++;
    }

    return count;
}
