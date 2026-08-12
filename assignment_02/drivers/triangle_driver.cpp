#include "algorithms.hpp"
#include "graph.hpp"
#include "timing.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    if (argc != 2) { std::cerr << "Usage: triangle_driver <test_file>\n"; return 1; }
    try {
        GraphInput input = read_undirected_adjacency_list(argv[1]);
        CSRGraph csr = adjacency_list_to_csr(input);
        std::vector<std::array<int,3>> triangles;
        double ms = 0.0;
        long long count = 0;
        ms = measure_ms([&]{ count = triangle_count(csr, input.vertices <= 100 ? &triangles : nullptr); });
        std::cout << "Algorithm: Triangle Counting\nTotal triangles: " << count << "\n";
        if (input.vertices <= 100) {
            std::cout << "Triangles found:\n";
            for (const auto& t : triangles) std::cout << "(" << t[0] << ", " << t[1] << ", " << t[2] << ")\n";
        }
        std::cout << std::fixed << std::setprecision(3) << "Execution time: " << ms << " ms\n";
    } catch (const std::exception& ex) { std::cerr << "Error: " << ex.what() << '\n'; return 2; }
}
