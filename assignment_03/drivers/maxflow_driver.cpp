#include "../include/csr_graph.hpp"
#include "../include/maxflow.hpp"

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char* argv[]) {

    if (argc != 2) {

        std::cerr
            << "Usage: "
            << argv[0]
            << " <input_file>\n";

        return 1;
    }

    std::ifstream file(argv[1]);

    if (!file) {

        std::cerr
            << "Error: Cannot open input file.\n";

        return 1;
    }

    int V;
    int E;

    file >> V >> E;

    if (V <= 1 || E < 0) {

        std::cerr
            << "Error: Invalid graph size.\n";

        return 1;
    }

    /*
     * Build the adjacency list first.
     *
     * This is preprocessing and therefore occurs
     * before the timed algorithm section.
     */
    std::vector<
        std::vector<std::pair<int, int>>
    > adjacency(V);

    for (int i = 0; i < V; ++i) {

        int vertex;
        int degree;

        file >> vertex >> degree;

        if (vertex != i || degree < 0) {

            std::cerr
                << "Error: Invalid adjacency row.\n";

            return 1;
        }

        for (int j = 0; j < degree; ++j) {

            int neighbor;
            int capacity;

            file >> neighbor >> capacity;

            if (neighbor < 0 ||
                neighbor >= V ||
                capacity <= 0) {

                std::cerr
                    << "Error: Invalid edge.\n";

                return 1;
            }

            adjacency[i].push_back(
                {neighbor, capacity}
            );
        }
    }

    std::string label;

    int source;
    int sink;

    file >> label >> source;

    if (label != "SOURCE") {

        std::cerr
            << "Error: Missing SOURCE.\n";

        return 1;
    }

    file >> label >> sink;

    if (label != "SINK") {

        std::cerr
            << "Error: Missing SINK.\n";

        return 1;
    }

    if (source < 0 ||
        source >= V ||
        sink < 0 ||
        sink >= V ||
        source == sink) {

        std::cerr
            << "Error: Invalid source/sink.\n";

        return 1;
    }

    /*
     * YOUR Assignment 1 CSR helper.
     *
     * Its execution time is deliberately outside
     * the measured algorithm section.
     */
    CSRGraph csr =
        convertToCSR(adjacency);

    /*
     * Only Maxflow-Mincut is timed.
     *
     * Residual-network initialization,
     * Dinic's algorithm, and min-cut extraction
     * all occur inside maxflowMincut().
     */
    auto start =
        std::chrono::steady_clock::now();

    MaxflowResult result =
        maxflowMincut(
            csr,
            source,
            sink
        );

    auto end =
        std::chrono::steady_clock::now();

    double time_ms =
        std::chrono::duration<double, std::milli>(
            end - start
        ).count();

    std::cout
        << "Algorithm: Maxflow-Mincut\n";

    std::cout
        << "Vertices: "
        << V
        << '\n';

    std::cout
        << "Source: "
        << source
        << '\n';

    std::cout
        << "Sink: "
        << sink
        << '\n';

    std::cout
        << "Maximum Flow: "
        << result.max_flow
        << '\n';

    std::cout
        << "Minimum Cut Capacity: "
        << result.cut_capacity
        << '\n';

    std::cout
        << "Flow = Cut: "
        << (
            result.max_flow ==
            result.cut_capacity
                ? "MATCH"
                : "MISMATCH"
        )
        << '\n';

    std::cout
        << "Execution Time: "
        << std::fixed
        << std::setprecision(6)
        << time_ms
        << " ms\n";

    return 0;
}
