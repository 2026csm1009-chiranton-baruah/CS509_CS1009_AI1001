#include <chrono>
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "../include/bfs.hpp"
#include "../include/csr.hpp"
#include "../include/dfs.hpp"
#include "../include/graph_io.hpp"
#include "../include/sssp.hpp"

namespace fs = std::filesystem;

using namespace std;
using namespace std::chrono;

string findTestFile(const string& filename)
{
    const string root = "assignment_01/tests";

    for (const auto& entry : fs::recursive_directory_iterator(root))
    {
        if (entry.is_regular_file() &&
            entry.path().filename() == filename)
        {
            return entry.path().string();
        }
    }

    return "";
}

void printTraversal(const vector<int>& traversal)
{
    cout << "\nTraversal Order\n";
    cout << "-------------------------\n";

    for (int v : traversal)
        cout << v << " ";

    cout << "\n";
}

void printBFSDistances(const vector<int>& distance)
{
    cout << "\nVertex\tDistance\n";

    for (size_t i = 0; i < distance.size(); i++)
    {
        cout << i << "\t";

        if (distance[i] == -1)
            cout << "INF";
        else
            cout << distance[i];

        cout << '\n';
    }
}

void printSSSPDistances(const vector<int>& distance)
{
    cout << "\nVertex\tDistance\n";

    for (size_t i = 0; i < distance.size(); i++)
    {
        cout << i << "\t";

        if (distance[i] == numeric_limits<int>::max())
            cout << "INF";
        else
            cout << distance[i];

        cout << '\n';
    }
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cerr << "Usage:\n";
        cerr << "./assignment1_driver <algorithm> <testfile>\n\n";
        cerr << "Algorithms:\n";
        cerr << "1 = BFS\n";
        cerr << "2 = DFS\n";
        cerr << "3 = SSSP\n";
        return 1;
    }

    int algorithm = stoi(argv[1]);

    string filename = argv[2];

    string fullPath = findTestFile(filename);

    if (fullPath.empty())
    {
        cerr << "Error: Cannot locate " << filename << '\n';
        return 1;
    }

    AdjacencyList graph;

    int source;
    int vertices;
    int edges;

    bool success = false;

    if (algorithm == 3)
    {
        success = loadWeightedGraph(
            fullPath,
            graph,
            source,
            vertices,
            edges);
    }
    else
    {
        success = loadUnweightedGraph(
            fullPath,
            graph,
            source,
            vertices,
            edges);
    }

    if (!success)
        return 1;

    CSRGraph csr = convertToCSR(graph);

    auto start = high_resolution_clock::now();

    switch (algorithm)
    {
        case 1:
        {
            vector<int> distance;

            vector<int> traversal =
                BFS(csr, source, distance);

            auto stop = high_resolution_clock::now();

            cout << "\n========== BFS ==========\n";

            printTraversal(traversal);
            printBFSDistances(distance);

            cout << "\nExecution Time: "
                 << duration_cast<microseconds>(stop - start).count()
                 << " us\n";

            break;
        }

        case 2:
        {
            vector<int> traversal =
                DFS(csr, source);

            auto stop = high_resolution_clock::now();

            cout << "\n========== DFS ==========\n";

            printTraversal(traversal);

            cout << "\nExecution Time: "
                 << duration_cast<microseconds>(stop - start).count()
                 << " us\n";

            break;
        }

        case 3:
        {
            vector<int> distance =
                Dijkstra(csr, source);

            auto stop = high_resolution_clock::now();

            cout << "\n======= SSSP (Dijkstra) =======\n";

            printSSSPDistances(distance);

            cout << "\nExecution Time: "
                 << duration_cast<microseconds>(stop - start).count()
                 << " us\n";

            break;
        }

        default:
            cerr << "Invalid algorithm selected.\n";
            return 1;
    }

    return 0;
}
