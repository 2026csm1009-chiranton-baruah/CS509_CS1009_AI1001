# CS509 – Assignment 3 (Buddy Category)

## Student Information

- Course: CS509 – PG Software Lab
- Mode of Assignment: Buddy (Groups of two)
- Member 1: Chiranton Baruah
- Entry Number: 2026CSM1009
- Member 2: Abhijeet Damodar
- Entry Number: 2026AIM1001

---

# Objective

This assignment contains two algorithmic problems:

1. Maxflow-Mincut
2. Gradient Descent

Both implementations are written in C++17. The code is separated into
header and source files and different test cases are used to check the
correctness and performance of the implementations.

For Maxflow-Mincut, the program calculates the maximum flow between a
source and a sink and then obtains a corresponding minimum cut.

For Gradient Descent, the program works on a polynomial and repeatedly
updates the value of x using the gradient until the stopping condition is
reached or the maximum number of iterations is completed.

---

# Directory Structure

```text
assignment_03/
|
├── drivers/
|   ├── maxflow_driver.cpp
|   └── gradient_descent_driver.cpp
|
├── include/
|   ├── csr_graph.hpp
|   ├── maxflow.hpp
|   └── gradient_descent.hpp
|
├── src/
|   ├── maxflow.cpp
|   └── gradient_descent.cpp
|
├── tests/
|   ├── maxflow/
|   |   ├── maxflow_10.txt
|   |   ├── maxflow_20.txt
|   |   ├── maxflow_100.txt
|   |   ├── maxflow_1000.txt
|   |   ├── maxflow_10000.txt
|   |   └── maxflow_50000.txt
|   |
|   └── gradient_descent/
|       ├── gd_edge_001.txt
|       ├── gd_edge_002.txt
|       ├── gd_edge_003.txt
|       ├── gd_edge_004.txt
|       ├── gd_edge_005.txt
|       ├── gd_edge_006.txt
|       ├── gd_edge_007.txt
|       ├── gd_edge_008.txt
|       ├── gd_edge_009.txt
|       └── gd_edge_010.txt
|
└── build/
```

---

# Compilation

Maxflow can be compiled using:

```bash
g++ -std=c++17 -Wall -Wextra -O2 -Iinclude     src/maxflow.cpp drivers/maxflow_driver.cpp     -o build/maxflow_driver
```

Gradient Descent can be compiled using:

```bash
g++ -std=c++17 -Wall -Wextra -O2 -Iinclude     src/gradient_descent.cpp drivers/gradient_descent_driver.cpp     -o build/gradient_descent_driver
```

---

# Task 1 – Maxflow-Mincut

## Implementation

The Maxflow part works on a directed graph where every edge has a
capacity.

A residual graph is maintained during the algorithm. BFS is used to make
the level graph and DFS is used to push flow through the available paths.

This process continues until no more flow can be sent from the source to
the sink.

After the maximum flow is found, the final residual graph is checked from
the source. The reachable vertices form one side of the minimum cut and
the remaining vertices form the other side.

The capacities of the original edges crossing between the two sides are
added to get the minimum cut capacity.

The main correctness check is:

```text
Maximum Flow = Minimum Cut Capacity
```

---

# Maxflow Test Cases

The following test cases were used:

| Test File | Vertices | Maximum Flow | Minimum Cut |
|-----------|---------:|-------------:|------------:|
| maxflow_10.txt | 6 | 23 | 23 |
| maxflow_100.txt | 100 | 100 | 100 |
| maxflow_1000.txt | 1000 | 100 | 100 |
| maxflow_10000.txt | 10000 | 100 | 100 |
| maxflow_50000.txt | 50000 | 100 | 100 |

All five tests passed and the flow value matched the cut capacity in
every test.

---

# Maxflow Performance

The recorded execution times are:

| Test File | Vertices | Execution Time (ms) | Result |
|-----------|---------:|--------------------:|--------|
| maxflow_10.txt | 6 | 0.012019 | PASS |
| maxflow_100.txt | 100 | 0.099050 | PASS |
| maxflow_1000.txt | 1000 | 0.422720 | PASS |
| maxflow_10000.txt | 10000 | 2.830699 | PASS |
| maxflow_50000.txt | 50000 | 8.898401 | PASS |

### Maxflow Test Summary

```text
Total : 5
Passed: 5
Failed: 0
```

For all five tests:

```text
Flow = Cut: MATCH
```

---

# Task 2 – Gradient Descent

## Implementation

Gradient Descent is used to find a suitable value of x for a polynomial.

The algorithm starts with an initial value of x and uses the derivative
of the polynomial as the gradient.

The update used is:

```text
x = x - learning_rate * gradient
```

The process is repeated until the required condition is reached or the
maximum number of iterations is completed.

The program also reports whether the test converged.

---

# Gradient Descent Test Cases

Ten test cases were used to check different polynomial situations.

| Test File | Degree | Final x | Final f(x) | Iterations | Converged | Result |
|-----------|-------:|--------:|-----------:|-----------:|:---------:|:------:|
| gd_edge_001.txt | 0 | 100.0000000000 | 5.0000000000 | 0 | Yes | PASS |
| gd_edge_002.txt | 1 | -3.0000000000 | -7.0000000000 | 100 | No | PASS |
| gd_edge_003.txt | 2 | 0.0000000000 | 0.0000000000 | 0 | Yes | PASS |
| gd_edge_004.txt | 2 | 1.9999999951 | 0.0000000000 | 211 | Yes | PASS |
| gd_edge_005.txt | 2 | 99.9810018809 | 8996.3907182952 | 100 | No | PASS |
| gd_edge_006.txt | 2 | 5.0000000000 | 0.0000000000 | 140 | Yes | PASS |
| gd_edge_007.txt | 4 | 4.3919539422 | -2.8902767752 | 10000 | No | PASS |
| gd_edge_008.txt | 2 | 0.0000000025 | 0.0000000000 | 96 | Yes | PASS |
| gd_edge_009.txt | 2 | -1.0000000000 | -1.0000000000 | 0 | Yes | PASS |
| gd_edge_010.txt | 2 | 18.3000000000 | 225.0900000000 | 1 | No | PASS |

---

# Gradient Descent Performance

The measured execution times are:

| Test File | Execution Time (ms) | Result |
|-----------|--------------------:|--------|
| gd_edge_001.txt | 0.0001310000 | PASS |
| gd_edge_002.txt | 0.0002720000 | PASS |
| gd_edge_003.txt | 0.0001150000 | PASS |
| gd_edge_004.txt | 0.0008580000 | PASS |
| gd_edge_005.txt | 0.0004650000 | PASS |
| gd_edge_006.txt | 0.0006740000 | PASS |
| gd_edge_007.txt | 0.0772860000 | PASS |
| gd_edge_008.txt | 0.0004870000 | PASS |
| gd_edge_009.txt | 0.0001400000 | PASS |
| gd_edge_010.txt | 0.0001430000 | PASS |

### Gradient Descent Test Summary

```text
Total : 10
Passed: 10
Failed: 0
```

---

# Input and Output

## Maxflow-Mincut

The Maxflow test files contain a directed graph with capacities and the
source and sink vertices.

The output includes:

- number of vertices
- source
- sink
- maximum flow
- minimum cut capacity
- flow and cut comparison
- execution time
- test result

Example:

```text
Maximum Flow: 23
Minimum Cut Capacity: 23
Flow = Cut: MATCH
```

---

## Gradient Descent

The Gradient Descent tests contain the polynomial and the parameters
needed for the calculation.

The output includes:

- degree
- final x
- final f(x)
- number of iterations
- convergence status
- execution time
- test result

---

# Performance Measurement

Execution time is measured using C++'s high resolution clock.

For Maxflow, the main Maxflow-Mincut processing is measured.

For Gradient Descent, the gradient descent calculation is measured.

The exact time can vary slightly depending on the compiler, computer and
background processes.

---

# Software Requirements

- C++17
- GNU g++
- Linux / WSL2
- Standard C++ library

The programs were compiled using:

```text
g++ -std=c++17 -Wall -Wextra -O2
```

---

# Final Result

The Maxflow test suite completed successfully:

```text
Total : 5
Passed: 5
Failed: 0
```

The Gradient Descent test suite also completed successfully:

```text
Total : 10
Passed: 10
Failed: 0
```

For Maxflow, the maximum flow was equal to the minimum cut capacity for
all tested graphs.

For Gradient Descent, all ten provided test cases passed. Some cases
converged before the iteration limit, while some reached the maximum
number of iterations and were correctly reported as not converged.

---

# Conclusion

This assignment contains implementations of Maxflow-Mincut and Gradient
Descent using separate C++ modules.

The Maxflow tests were used to check correctness and performance on
different graph sizes. The flow and cut values matched in all tested
cases.

The Gradient Descent tests covered different polynomial degrees and
different convergence situations.

Overall, all the provided test cases passed successfully.
