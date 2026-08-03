#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Edge
{
    int src;
    int dest;
    int weight;
};

void DFS(int u,
         const vector<int>& row_ptr,
         const vector<int>& col_idx,
         vector<bool>& visited)
{
    visited[u] = true;

    cout << u << " ";

    for (int e = row_ptr[u]; e < row_ptr[u + 1]; e++)
    {
        int v = col_idx[e];

        if (!visited[v])
            DFS(v, row_ptr, col_idx, visited);
    }
}

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

    // Build CSR
    vector<int> row_ptr(V + 1, 0);
    vector<int> col_idx(E);
    vector<int> weights(E);

    for (const auto &e : edges)
        row_ptr[e.src + 1]++;

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
    cout << "CSR Representation\n\n";

    cout << "row_ptr : ";
    for (int x : row_ptr)
        cout << x << " ";

    cout << "\n";

    cout << "col_idx : ";
    for (int x : col_idx)
        cout << x << " ";

    cout << "\n";

    cout << "weights : ";
    for (int x : weights)
        cout << x << " ";

    cout << "\n\n";

    vector<bool> visited(V, false);

    cout << "DFS Traversal starting from vertex "
         << source
         << ":\n\n";

    DFS(source, row_ptr, col_idx, visited);

    cout << endl;

    return 0;
}
