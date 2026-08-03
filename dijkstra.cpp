#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge
{
    int src;
    int dest;
    int weight;
};

int main()
{
    ifstream fin("graph.txt");

    if (!fin)
    {
        cout << "Cannot open input file.\n";
        return 1;
    }

    int V, E;
    fin >> V >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; i++)
    {
        fin >> edges[i].src
            >> edges[i].dest
            >> edges[i].weight;
    }

    int source;
    fin >> source;

    fin.close();

    // Sort edges by source vertex
    sort(edges.begin(), edges.end(),
         [](const Edge &a, const Edge &b)
         {
             if (a.src == b.src)
                 return a.dest < b.dest;
             return a.src < b.src;
         });

    // CSR Arrays
    vector<int> row_ptr(V + 1, 0);
    vector<int> col_idx(E);
    vector<int> weights(E);

    // Count outgoing edges
    for (const auto &e : edges)
        row_ptr[e.src + 1]++;

    // Prefix sum
    for (int i = 1; i <= V; i++)
        row_ptr[i] += row_ptr[i - 1];

    vector<int> current = row_ptr;

    for (const auto &e : edges)
    {
        int pos = current[e.src]++;
        col_idx[pos] = e.dest;
        weights[pos] = e.weight;
    }

    // Print CSR
    cout << "\nCSR Representation\n";

    cout << "row_ptr : ";
    for (int x : row_ptr)
        cout << x << " ";

    cout << "\ncol_idx : ";
    for (int x : col_idx)
        cout << x << " ";

    cout << "\nweights : ";
    for (int x : weights)
        cout << x << " ";

    cout << "\n\n";

    // Dijkstra
    vector<int> dist(V, INF);

    dist[source] = 0;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({0, source});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u])
            continue;

        for (int e = row_ptr[u];
             e < row_ptr[u + 1];
             e++)
        {
            int v = col_idx[e];
            int w = weights[e];

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source "
         << source << "\n\n";

    for (int i = 0; i < V; i++)
    {
        cout << "Vertex "
             << i
             << " : ";

        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;
}
