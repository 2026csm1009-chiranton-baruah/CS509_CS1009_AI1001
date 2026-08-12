#include "algorithms.hpp"
#include "graph.hpp"
#include "timing.hpp"
#include <iomanip>
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) { std::cerr << "Usage: bc_driver <test_file>\n"; return 1; }
    try {
        GraphInput input = read_undirected_adjacency_list(argv[1]);
        CSRGraph csr = adjacency_list_to_csr(input);
        std::vector<double> values;
        double ms = measure_ms([&]{ values = betweenness_centrality(csr); });
        std::cout << "Algorithm: Betweenness Centrality\nVertex Centrality\n";
        std::cout << std::fixed << std::setprecision(2);
        for (int u = 0; u < input.vertices; ++u) std::cout << u << ' ' << values[u] << '\n';
        std::cout << std::setprecision(3) << "Execution time: " << ms << " ms\n";
    } catch (const std::exception& ex) { std::cerr << "Error: " << ex.what() << '\n'; return 2; }
}
