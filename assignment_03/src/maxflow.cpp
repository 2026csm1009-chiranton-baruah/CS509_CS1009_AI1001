#include "maxflow.h"
#include <queue>
#include <algorithm>
#include <limits>

struct FlowEdge
{
    int to;
    int rev;
    int cap;
};

void addEdge(
    vector<vector<FlowEdge>>& g,
    int u,
    int v,
    int cap
)
{
    FlowEdge a = {v, (int)g[v].size(), cap};
    FlowEdge b = {u, (int)g[u].size(), 0};

    g[u].push_back(a);
    g[v].push_back(b);
}

bool bfs(
    vector<vector<FlowEdge>>& g,
    int source,
    int sink,
    vector<int>& level
)
{
    fill(level.begin(), level.end(), -1);

    queue<int> q;
    q.push(source);
    level[source] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto& e : g[u])
        {
            if (e.cap > 0 && level[e.to] == -1)
            {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }

    return level[sink] != -1;
}

int dfs(
    vector<vector<FlowEdge>>& g,
    vector<int>& level,
    vector<int>& ptr,
    int u,
    int sink,
    int flow
)
{
    if (u == sink)
        return flow;

    while (ptr[u] < g[u].size())
    {
        FlowEdge& e = g[u][ptr[u]];

        if (e.cap > 0 && level[e.to] == level[u] + 1)
        {
            int pushed = dfs(
                g,
                level,
                ptr,
                e.to,
                sink,
                min(flow, e.cap)
            );

            if (pushed > 0)
            {
                e.cap -= pushed;
                g[e.to][e.rev].cap += pushed;
                return pushed;
            }
        }

        ptr[u]++;
    }

    return 0;
}

Result maxFlow(
    const csrgraph& csr,
    int source,
    int sink
)
{
    int n = csr.rowPtr.size() - 1;

    vector<vector<FlowEdge>> g(n);

    
    for (int u = 0; u < n; u++)
    {
        for (int i = csr.rowPtr[u];
             i < csr.rowPtr[u + 1];
             i++)
        {
            addEdge(
                g,
                u,
                csr.colIdx[i],
                csr.values[i]
            );
        }
    }

    int flow = 0;
    vector<int> level(n);
    vector<int> ptr(n);

    while (bfs(g, source, sink, level))
    {
        fill(ptr.begin(), ptr.end(), 0);

        while (true)
        {
            int pushed = dfs(
                g,
                level,
                ptr,
                source,
                sink,
                numeric_limits<int>::max()
            );

            if (pushed == 0)
                break;

            flow += pushed;
        }
    }

    
    vector<int> seen(n, 0);
    queue<int> q;

    q.push(source);
    seen[source] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto& e : g[u])
        {
            if (e.cap > 0 && !seen[e.to])
            {
                seen[e.to] = 1;
                q.push(e.to);
            }
        }
    }

    Result ans;
    ans.flow = flow;

    for (int i = 0; i < n; i++)
    {
        if (seen[i])
            ans.side1.push_back(i);
        else
            ans.side2.push_back(i);
    }

    
    for (int u = 0; u < n; u++)
    {
        if (!seen[u])
            continue;

        for (int i = csr.rowPtr[u];
             i < csr.rowPtr[u + 1];
             i++)
        {
            int v = csr.colIdx[i];

            if (!seen[v])
            {
                ans.cut.push_back(
                    {u, v, csr.values[i]}
                );
            }
        }
    }

    return ans;
}
