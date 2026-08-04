#include "../include/csr.hpp"

CSRGraph convertToCSR(const AdjacencyList& graph)
{
    CSRGraph csr;

    csr.vertices = static_cast<int>(graph.size());

    csr.row_ptr.reserve(csr.vertices + 1);

    csr.row_ptr.push_back(0);

    int edgeCount = 0;

    for (const auto& neighbours : graph)
    {
        edgeCount += static_cast<int>(neighbours.size());

        csr.row_ptr.push_back(edgeCount);

        for (const auto& edge : neighbours)
        {
            csr.col_idx.push_back(edge.destination);
            csr.values.push_back(edge.weight);
        }
    }

    csr.edges = edgeCount;

    return csr;
}
