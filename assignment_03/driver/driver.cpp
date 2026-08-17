#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

#include "../../assignment_01/src/csr.h"
#include "../src/maxflow.h"

using namespace std;
using namespace chrono;

const string TEST_FILE = "tests/maxflow_10000.txt";

int main()
{
    ifstream fin(TEST_FILE);

    if (!fin)
    {
        cout << "Could not open input file." << endl;
        return 1;
    }

    int n, m;
    fin >> n >> m;

    vector<vector<int>> graph(n);
    vector<vector<int>> capacity(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        int u, degree;
        fin >> u >> degree;

        for (int j = 0; j < degree; j++)
        {
            int v, cap;
            fin >> v >> cap;

            graph[u].push_back(v);
            capacity[u][v] = cap;
        }
    }

    string word;
    int source, sink;

    fin >> word >> source;
    fin >> word >> sink;

    fin.close();

    auto start = high_resolution_clock::now();

    FlowResult ans =
        maxFlow(graph, capacity, source, sink);

    auto stop = high_resolution_clock::now();

    double time =
        duration_cast<microseconds>(stop - start).count()
        / 1000.0;

    int cutValue = 0;

    for (auto& e : ans.cutEdges)
        cutValue += e.cap;

    cout << "Algorithm: Maxflow-Mincut" << endl;
    cout << "Source: " << source << endl;
    cout << "Sink: " << sink << endl;
    cout << "Maximum flow: " << ans.maxFlow << endl;
    cout << "Minimum cut capacity: " << cutValue << endl;

    cout << "Source side: ";
    for (int x : ans.sourceSide)
        cout << x << " ";

    cout << "\nSink side: ";
    for (int x : ans.sinkSide)
        cout << x << " ";

    cout << "\nCut edges:" << endl;

    for (auto& e : ans.cutEdges)
        cout << e.u << " " << e.v << " " << e.cap << endl;

    cout << "Execution time: " << time << " ms" << endl;

    return 0;
}
