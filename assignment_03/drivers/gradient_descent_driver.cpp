#include "../include/gradient_descent.hpp"

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
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

    std::string label;

    int degree;

    file >> label >> degree;

    if (label != "DEGREE" || degree < 0) {
        std::cerr
            << "Error: Invalid degree.\n";

        return 1;
    }

    file >> label;

    if (label != "COEFFICIENTS") {
        std::cerr
            << "Error: Missing coefficients.\n";

        return 1;
    }

    std::vector<double> coefficients(
        degree + 1
    );

    for (double& coefficient : coefficients) {

        if (!(file >> coefficient)) {

            std::cerr
                << "Error: Expected "
                << degree + 1
                << " coefficients.\n";

            return 1;
        }
    }

    double initial_x;
    double learning_rate;
    double tolerance;
    int max_iterations;

    file >> label >> initial_x;
    file >> label >> learning_rate;
    file >> label >> tolerance;
    file >> label >> max_iterations;

    if (learning_rate <= 0 ||
        tolerance <= 0 ||
        max_iterations <= 0) {

        std::cerr
            << "Error: Invalid optimization parameters.\n";

        return 1;
    }

    /*
     * Only the algorithm call is timed.
     */
    auto start =
        std::chrono::steady_clock::now();

    GradientDescentResult result =
        gradientDescent(
            coefficients,
            initial_x,
            learning_rate,
            tolerance,
            max_iterations
        );

    auto end =
        std::chrono::steady_clock::now();

    double time_ms =
        std::chrono::duration<double, std::milli>(
            end - start
        ).count();

    std::cout << std::fixed
              << std::setprecision(10);

    std::cout
        << "Algorithm: Gradient Descent\n";

    std::cout
        << "Degree: "
        << degree
        << '\n';

    std::cout
        << "Final x: "
        << result.final_x
        << '\n';

    std::cout
        << "Final f(x): "
        << result.final_fx
        << '\n';

    std::cout
        << "Iterations: "
        << result.iterations
        << '\n';

    std::cout
        << "Converged: "
        << (result.converged ? "Yes" : "No")
        << '\n';

    std::cout
        << "Execution time: "
        << time_ms
        << " ms\n";

    return 0;
}
