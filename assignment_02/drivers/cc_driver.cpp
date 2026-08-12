#include "algorithms.hpp"
#include "graph.hpp"
#include "timing.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) { std::cerr << "Usage: cc_driver <test_file>\n"; return 1; }
    try {
        GraphInput input = read_undirected_adjacency_list(argv[1]);
        CSRGraph csr = adjacency_list_to_csr(input);
        int k = 0;
        std::vector<int> comp;
        double ms = measure_ms([&]{ comp = connected_components(csr, k); });
        std::cout << "Algorithm: Connected Components\nNumber of components: " << k << "\nVertex Component\n";
        for (int u = 0; u < input.vertices; ++u) std::cout << u << ' ' << comp[u] << '\n';
        std::cout << "Execution time: " << ms << " ms\n";
    } catch (const std::exception& ex) { std::cerr << "Error: " << ex.what() << '\n'; return 2; }
}
