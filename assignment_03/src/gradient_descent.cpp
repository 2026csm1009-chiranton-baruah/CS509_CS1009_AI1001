#include "../include/gradient_descent.hpp"

#include <cmath>

double evaluatePolynomial(
    const std::vector<double>& coefficients,
    double x
) {
    if (coefficients.empty()) {
        return 0.0;
    }

    // Horner's method
    double result = coefficients.back();

    for (int i = static_cast<int>(coefficients.size()) - 2;
         i >= 0;
         --i) {
        result = result * x + coefficients[i];
    }

    return result;
}

double evaluateDerivative(
    const std::vector<double>& coefficients,
    double x
) {
    if (coefficients.size() <= 1) {
        return 0.0;
    }

    int degree = static_cast<int>(coefficients.size()) - 1;

    // Horner evaluation of:
    // c1 + 2*c2*x + ... + d*cd*x^(d-1)
    double result =
        degree * coefficients[degree];

    for (int i = degree - 1; i >= 1; --i) {
        result = result * x + i * coefficients[i];
    }

    return result;
}

GradientDescentResult gradientDescent(
    const std::vector<double>& coefficients,
    double initial_x,
    double learning_rate,
    double tolerance,
    int max_iterations
) {
    GradientDescentResult result{};

    double x = initial_x;
    int iterations = 0;
    bool converged = false;

    for (int i = 0; i < max_iterations; ++i) {

        double gradient =
            evaluateDerivative(coefficients, x);

        if (std::abs(gradient) <= tolerance) {
            converged = true;
            break;
        }

        x = x - learning_rate * gradient;
        ++iterations;
    }

    result.final_x = x;
    result.final_fx =
        evaluatePolynomial(coefficients, x);
    result.iterations = iterations;
    result.converged = converged ||
        std::abs(evaluateDerivative(coefficients, x))
            <= tolerance;

    return result;
}
