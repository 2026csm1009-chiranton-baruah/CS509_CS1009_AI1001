#include "../include/graph_io.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

bool loadUnweightedGraph(
    const std::string& filename,
    AdjacencyList& graph,
    int& source,
    int& vertices,
    int& edges)
{
    std::ifstream fin(filename);

    if (!fin.is_open())
    {
        std::cerr << "Unable to open file: "
                  << filename << '\n';
        return false;
    }

    fin >> vertices >> edges;

    graph.assign(vertices, {});

    for (int i = 0; i < vertices; i++)
    {
        int u;
        int degree;

        fin >> u >> degree;

        for (int j = 0; j < degree; j++)
        {
            int v;
            fin >> v;

            graph[u].push_back(Edge(v, 1));
        }
    }

    std::string token;
    fin >> token >> source;

    return true;
}

bool loadWeightedGraph(
    const std::string& filename,
    AdjacencyList& graph,
    int& source,
    int& vertices,
    int& edges)
{
    std::ifstream fin(filename);

    if (!fin.is_open())
    {
        std::cerr << "Unable to open file: "
                  << filename << '\n';
        return false;
    }

    fin >> vertices >> edges;

    graph.assign(vertices, {});

    for (int i = 0; i < vertices; i++)
    {
        int u;
        int degree;

        fin >> u >> degree;

        for (int j = 0; j < degree; j++)
        {
            int v;
            int w;

            fin >> v >> w;

            graph[u].push_back(Edge(v, w));
        }
    }

    std::string token;
    fin >> token >> source;

    return true;
}
