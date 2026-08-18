#ifndef GRADIENT_DESCENT_HPP
#define GRADIENT_DESCENT_HPP

#include <vector>

struct GradientDescentResult {
    double final_x;
    double final_fx;
    int iterations;
    bool converged;
};

double evaluatePolynomial(
    const std::vector<double>& coefficients,
    double x
);

double evaluateDerivative(
    const std::vector<double>& coefficients,
    double x
);

GradientDescentResult gradientDescent(
    const std::vector<double>& coefficients,
    double initial_x,
    double learning_rate,
    double tolerance,
    int max_iterations
);

#endif
