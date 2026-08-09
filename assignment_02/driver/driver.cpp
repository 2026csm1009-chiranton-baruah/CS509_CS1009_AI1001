#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

#include "../../assignment_01/src/csr.h"
#include "../src/triangle.h"
#include "../src/connected.h"

using namespace std;
using namespace chrono;

const string TRIANGLE_FILE = "tests/tc_10.txt";
const string COMPONENT_FILE = "tests/cc_10.txt";

int main()
{
    int choice;

    cout << "1. Triangle Counting" << endl;
    cout << "2. Connected Components" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        ifstream inputFile(TRIANGLE_FILE);

        if (!inputFile)
        {
            cout << "Could not open triangle test file." << endl;
            return 1;
        }

        int vertices, edgeCount;
        inputFile >> vertices >> edgeCount;

        vector<vector<int>> graph(vertices);

        for (int i = 0; i < vertices; i++)
        {
            int vertex, degree;
            inputFile >> vertex >> degree;

            for (int j = 0; j < degree; j++)
            {
                int neighbour;
                inputFile >> neighbour;

                graph[vertex].push_back(neighbour);
            }
        }

        inputFile.close();

        // Sort the neighbours before converting to CSR
        for (int i = 0; i < vertices; i++)
        {
            sort(graph[i].begin(), graph[i].end());
        }

        vector<int> offset;
        vector<int> edges;

        // CSR conversion is preprocessing
        convertToCSR(graph, offset, edges);

        vector<vector<int>> triangles;

        auto start = high_resolution_clock::now();

        int totalTriangles =
            countTriangles(offset, edges, triangles);

        auto stop = high_resolution_clock::now();

        auto timeTaken =
            duration_cast<microseconds>(stop - start);

        cout << "\nAlgorithm: Triangle Counting" << endl;
        cout << "Total triangles: "
             << totalTriangles << endl;

        cout << "Triangles found:" << endl;

        for (int i = 0; i < triangles.size(); i++)
        {
            cout << "("
                 << triangles[i][0] << ", "
                 << triangles[i][1] << ", "
                 << triangles[i][2] << ")"
                 << endl;
        }

        cout << "Execution time: "
             << timeTaken.count() / 1000.0
             << " ms" << endl;
    }
    else if (choice == 2)
    {
        ifstream inputFile(COMPONENT_FILE);

        if (!inputFile)
        {
            cout << "Could not open connected components test file."
                 << endl;
            return 1;
        }

        int vertices, edgeCount;
        inputFile >> vertices >> edgeCount;

        vector<vector<int>> graph(vertices);

        for (int i = 0; i < vertices; i++)
        {
            int vertex, degree;
            inputFile >> vertex >> degree;

            for (int j = 0; j < degree; j++)
            {
                int neighbour;
                inputFile >> neighbour;

                graph[vertex].push_back(neighbour);
            }
        }

        inputFile.close();

        vector<int> offset;
        vector<int> edges;

        // Convert the graph into CSR
        convertToCSR(graph, offset, edges);

        vector<int> component;

        auto start = high_resolution_clock::now();

        int totalComponents =
            connectedComponents(offset, edges, component);

        auto stop = high_resolution_clock::now();

        auto timeTaken =
            duration_cast<microseconds>(stop - start);

        cout << "\nAlgorithm: Connected Components" << endl;

        cout << "Number of components: "
             << totalComponents << endl;

        cout << "\nVertex Component" << endl;

        for (int i = 0; i < vertices; i++)
        {
            cout << i << " "
                 << component[i] << endl;
        }

        cout << "Execution time: "
             << timeTaken.count() / 1000.0
             << " ms" << endl;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
