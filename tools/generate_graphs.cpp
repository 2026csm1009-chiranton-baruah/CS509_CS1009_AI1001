#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

mt19937 rng(random_device{}());

void generateBFS(const string& filename, int V)
{
    ofstream out(filename);

    int E = 0;

    vector<vector<int>> graph(V);

    uniform_int_distribution<int> degreeDist(1, 4);

    for (int i = 0; i < V - 1; i++)
    {
        graph[i].push_back(i + 1);

        int degree = degreeDist(rng);

        for (int j = 1; j < degree; j++)
        {
            int v = uniform_int_distribution<int>(i + 1, V - 1)(rng);

            if (v != i)
                graph[i].push_back(v);
        }
    }

    for (auto& adj : graph)
        E += adj.size();

    out << V << " " << E << "\n";

    for (int i = 0; i < V; i++)
    {
        out << i << " " << graph[i].size();

        for (int v : graph[i])
            out << " " << v;

        out << "\n";
    }

    out << "SOURCE 0\n";
}

void generateSSSP(const string& filename, int V)
{
    ofstream out(filename);

    int E = 0;

    vector<vector<pair<int,int>>> graph(V);

    uniform_int_distribution<int> degreeDist(1,4);
    uniform_int_distribution<int> weightDist(1,20);

    for (int i = 0; i < V - 1; i++)
    {
        graph[i].push_back({i+1, weightDist(rng)});

        int degree = degreeDist(rng);

        for (int j = 1; j < degree; j++)
        {
            int v = uniform_int_distribution<int>(i+1, V-1)(rng);

            graph[i].push_back({v, weightDist(rng)});
        }
    }

    for (auto& adj : graph)
        E += adj.size();

    out << V << " " << E << "\n";

    for (int i = 0; i < V; i++)
    {
        out << i << " " << graph[i].size();

        for (auto edge : graph[i])
            out << " " << edge.first << " " << edge.second;

        out << "\n";
    }

    out << "SOURCE 0\n";
}

int main()
{
    vector<int> sizes =
    {
        10,
        100,
        5000,
        10000,
        50000,
        100000
    };

    for (int n : sizes)
    {
        generateBFS(
            "../assignment_01/tests/bfs_" + to_string(n) + ".txt",
            n);

        generateBFS(
            "../assignment_01/tests/dfs_" + to_string(n) + ".txt",
            n);

        generateSSSP(
            "../assignment_01/tests/sssp_" + to_string(n) + ".txt",
            n);

        cout << "Generated " << n << endl;
    }
}
