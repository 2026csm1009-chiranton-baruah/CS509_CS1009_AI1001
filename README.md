# CS509 – Assignment 1 (Buddy Category)

## Student Information

- **Course:** CS509 – PG Software Lab
- **Mode of Assignment:** Buddy (Groups of two)
- **Member 1:** Chiranton Baruah
- **Entry Number:** 2026CSM1009
- **Member 2:** Abhijeet Damodar
- **Entry Number:** 2026AIM1001

---

# Objective

This assignment implements two fundamental data algorithms:

1. Breadth-first search (BFS)
2. Depth-first search (DFS)
3. Single source shortest path (SSSP) using Dijkstra's algorithm

Both implementations are written in C++17 and executed through a common menu-driven driver.

---

# Directory Structure

```
assignment_01/
│
├── driver/
│   └── assignment1_driver.cpp
│
├── include/
│   ├── bfs.hpp
│   └── csr.hpp
|   ...
│
├── src/
│   ├── bfs.cpp
│   ├── csr.cpp
│   ├── dfs.cpp
│   └── graph_io.cpp
│   ...
|
├── tests/
│   ├── bfs_*.txt
│   └── dfs_*.txt
│
.   ...
.   ...
.   ...
│
└── Makefile
```

---

# Compilation

Compile the project using:

```bash
make
```

Remove the executable using:

```bash
make clean
```

---

# Running

Execute:

```bash
./bin/wrapper
```

---

# Menu

```
======================================
      CS509 Assignment 1
======================================
1. Assignment 1
0. Exit

Enter choice:
```

---

# Task 1 — Breadth first search (BFS)

## Implementations

Here, we are using a queue to traverse every neighbor of a node before traversing every neighbor of those neighboring nodes. 

Time Complexity:

```
O(V + E)
```
where V is the number of vertices and E is the number of edges in the graph.

---

# Task 2 - Depth first search (DFS)

## Implementations

Here, we are using a stack data structure to traverse all descendants of a node before traversing towards unexplored descendants until all nodes have been traversed.

Time Complexity:

```
O(V + E)
```
where V is the number of vertices and E is the number of edges in the graph.

---

# Task 3 - Single Source Shortest Path (SSSP) using Dijkstra's Algorithm

## Implementations
Here, we are using Dijkstra's algorithm to determine the single source shortest path from one node to all others across a graph


# BFS / DFS file format

Input files contain:

```
V E
u0 degree neighbor1 neighbor2 ...
u1 degree neighbor1 neighbor2 ...
...
u(V-1) degree neighbor1 neighbor2 ...
SOURCE s

```

Example:

```
5 5
0 2 1 2
1 2 0 3
2 3 0 3 4
3 2 1 2
4 1 2
SOURCE 0
```

---

# BFS / DFS Output

For each implementation:

- Resultant traversal
- Execution time of traversal in microseconds

---

# SSSP Input Format

Input lines contain

```
V E
u0 degree neighbor1 weight1 neighbor2 weight2 ...
u1 degree neighbor1 weight1 neighbor2 weight2 ...
...
u(V-1) degree neighbor1 weight1 neighbor2 weight2 ...
SOURCE s

```

---

## Example

```
5 6
0 2 1 4 2 1
1 1 3 1
2 2 1 2 3 5
3 1 4 3
4 0
SOURCE 0
```

---

# SSSP Output

The output displays

- Two-column table with vertices and distance from source of SSSP
- Execution time of SSSP calculations in microseconds

---


# CSR Graph Representation

The graph is initially supplied as an adjacency list and converted into Compressed Sparse Row (CSR) format.

The implementation supports:

- Unweighted graphs
- Weighted graphs

---

# Test Cases

The following graph sizes were prepared according to the follwing nomencalture.

---

```

algorithm_N.txt

```
where 'algorithm' can be 'bfs', 'dfs' or 'sssp' and 'N' (the number of vertices) can be 10, 100, 10000, 50000 and 100000

---

# Performance Measurement

Execution times are measured using

```
std::chrono::high_resolution_clock
```

Reported timings are in microseconds.

BFS Testcase
| Test File | Vertices (V) | Edges (E) | Graph Type | Conversion Time (microseconds) |
|-----------|-------------:|----------:|------------|---------------------:|
| bfs_10.txt | 10 | 15 | Connected Sparse | 2 |
| bfs_100.txt | 100 | 246 | Connected sparse | 6 |
| bfs_5000.txt | 5000 | 12550 | Connected sparse | 181 |
| bfs_10000.txt | 10000 | 25249 | Connected sparse | 218 |
| bfs_50000.txt | 50000 | 125038 | Connected sparse | 657 |
| bfs_100000.txt | 100000 | 250419 | Connected sparse | 5739 |

---
DFS Testcase
| Test File | Vertices (V) | Edges (E) | Graph Type | Conversion Time (microseconds) |
|-----------|-------------:|----------:|------------|---------------------:|
| dfs_10.txt | 10 | 15 | Connected Sparse | 3 |
| dfs_100.txt | 100 | 255 | Connected sparse | 6 |
| dfs_5000.txt | 5000 | 12395 | Connected sparse | 298 |
| dfs_10000.txt | 10000 | 25165 | Connected sparse | 323 |
| dfs_50000.txt | 50000 | 125141 | Connected sparse | 3363 |
| dfs_100000.txt | 100000 | 250108 | Connected sparse | 3032 |

---
SSSP Test Cases
| Test File | Vertices (V) | Edges (E) | Graph Type | Conversion Time (microseconds) |
|-----------|-------------:|----------:|------------|---------------------:|
| sssp_10.txt | 10 | 15 | Connected Sparse | 2 |
| sssp_100.txt | 100 | 255 | Connected sparse | 21 |
| sssp_5000.txt | 5000 | 12584 | Connected sparse | 1257 |
| sssp_10000.txt | 10000 | 25165 | Connected sparse | 1488 |
| sssp_50000.txt | 50000 | 125141 | Connected sparse | 6424 |
| sssp_100000.txt | 100000 | 250108 | Connected sparse | 12411 |

# Software Requirements

- C++17
- GNU g++
- GNU Make
- Linux / WSL2

---

# References

1. CS509 PG Software Lab – Assignment 1 Specification
2. C++17 Standard Library Documentation
3. GNU Compiler Collection (GCC)

# CS509 Laboratory Repository - Buddy Assignment 2

## Repository Overview

This repository contains the CS509 Assignment 2 Buddy task: Triangle Counting, Betweenness Centrality, and Connected Components on undirected graphs.

The assignment specification requires these three graph analytics tasks, CSR input for all three, dedicated drivers, algorithm-only timing, and result tables for every required test case.

## Language and Environment

- Language: C++17
- Compiler: g++ (GCC 11+ recommended)
- Optimization: `-O2`
- Warnings: `-Wall -Wextra -pedantic`
- Timing: `std::chrono::steady_clock`
- Platform: Linux / WSL / macOS / Windows MinGW with a POSIX-like shell

The course guidelines allow C or C++, recommend C++, and require the language and toolchain to remain consistent and documented in the README.

## Directory Structure

```text
CS509_Buddy_Assignment2/
├── README.md
├── common_wrapper/
│   └── wrapper.cpp
├── assignment_02/
│   ├── Makefile
│   ├── include/
│   │   ├── algorithms.hpp
│   │   ├── graph.hpp
│   │   └── timing.hpp
│   ├── src/
│   │   ├── algorithms.cpp
│   │   └── graph.cpp
│   ├── drivers/
│   │   ├── triangle_driver.cpp
│   │   ├── bc_driver.cpp
│   │   └── cc_driver.cpp
│   ├── tests/
│   │   ├── tc_10.txt, tc_100.txt, tc_10000.txt, tc_50000.txt, tc_100000.txt
│   │   ├── bc_10.txt, bc_100.txt, bc_1000.txt, bc_5000.txt, bc_10000.txt
│   │   └── cc_10.txt, cc_100.txt, cc_10000.txt, cc_50000.txt, cc_100000.txt
│   └── outputs/
└── tools/
    └── generate_tests.cpp
```

## Common Wrapper: Build and Usage

Build everything:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic common_wrapper/wrapper.cpp -o common_wrapper/wrapper
./common_wrapper/wrapper
```

The wrapper presents a single repository-level interface and dispatches to the dedicated Assignment 2 drivers. It supports building all algorithms and running one selected test file or all test files for an algorithm.

For direct use:

```bash
make -C assignment_02 all
./assignment_02/triangle_driver assignment_02/tests/tc_10.txt
./assignment_02/bc_driver assignment_02/tests/bc_100.txt
./assignment_02/cc_driver assignment_02/tests/cc_10.txt
```

## Assignment 02 - Buddy Task

### Assignment Mode

Double / Buddy.

### Objective

Implement and benchmark Triangle Counting, Betweenness Centrality, and Connected Components on undirected graphs, using adjacency-list input converted to CSR before timed algorithm execution.

### Algorithm / Approach

#### Triangle Counting

For each vertex `u`, only neighbor pairs with increasing vertex order are considered. A binary search in the sorted CSR neighbor list checks whether the pair is also connected. Each triangle is therefore counted once, so no post-division by three is needed in this optimized orientation-based implementation. Individual triangles are printed for the two smallest required sizes (`10` and `100`).

Complexity is approximately `O(sum(deg(u)^2 log deg(u)))` with binary-search membership checks; memory is `O(V + E)` for CSR plus the optional small triangle list.

#### Betweenness Centrality

Brandes' algorithm is implemented for unweighted graphs. A BFS is performed from every source vertex, predecessor lists and shortest-path counts are accumulated, and dependencies are propagated in reverse BFS order. Raw, unnormalized centrality is reported to two decimal places.

Time complexity: `O(VE)` for the sparse adjacency-list graph representation. Space complexity: `O(V + E)`.

#### Connected Components

A BFS begins at each unvisited vertex. Component IDs are assigned in the order components are first discovered, beginning at `0`, including isolated vertices.

Time complexity: `O(V + E)`. Space complexity: `O(V)` plus the CSR graph storage.

### Input Format

Each Assignment 2 graph test file uses:

```text
V E
u0 degree neighbor1 neighbor2 ...
u1 degree neighbor1 neighbor2 ...
...
u(V-1) degree neighbor1 neighbor2 ...
```

The graph is undirected. Each edge is listed in both endpoint adjacency lists, while `E` counts the undirected edge once. Vertex numbering is `0 .. V-1`. Isolated vertices are written as `u 0`.

### CSR Conversion

The adjacency list is validated and converted to CSR before the timer starts. The conversion code is kept outside the timed region, as required for CSR-based tasks.

> Integration note: the supplied Assignment 2 specification says the CSR conversion helper from Assignment 1 should be reused rather than copied. Because only the Assignment 2 PDFs were supplied here, this repository contains a standalone `adjacency_list_to_csr` helper with the same required interface so that the project is buildable. Replace that helper body with the pair's existing Assignment 1 implementation before final submission if the course repository already contains it.

### File Structure

- `assignment_02/src/algorithms.cpp`: Triangle Counting, Brandes Betweenness Centrality, Connected Components.
- `assignment_02/src/graph.cpp`: input validation and adjacency-list-to-CSR conversion.
- `assignment_02/drivers/*.cpp`: separate drivers for each Assignment 2 algorithm.
- `assignment_02/include/*.hpp`: public declarations and timing helper.
- `assignment_02/tests/*.txt`: one test case per file, using the required graph sizes.
- `tools/generate_tests.cpp`: deterministic C++17 generator used to create the provided test files.
- `tools/run_all.cpp`: C++17 utility that builds the Assignment 2 drivers and executes every required test file.
- `common_wrapper/wrapper.cpp`: C++17 repository-level wrapper for building and running Assignment 2.

### Compilation

```bash
make -C assignment_02 all
```

To compile one driver:

```bash
make -C assignment_02 triangle
make -C assignment_02 bc
make -C assignment_02 cc
```

### Execution

```bash
./assignment_02/triangle_driver assignment_02/tests/tc_10.txt
./assignment_02/bc_driver assignment_02/tests/bc_10.txt
./assignment_02/cc_driver assignment_02/tests/cc_10.txt
```

### Timing Rules

The timer starts immediately before the algorithm call and stops immediately after it. Input reading, validation, CSR conversion, output formatting, and printing are outside the timed region. The same `ms` unit is reported consistently.

### Required Test Sizes

Triangle Counting: `10, 100, 10,000, 50,000, 100,000` vertices.

Betweenness Centrality: `10, 100, 1,000, 5,000, 10,000` vertices.

Connected Components: `10, 100, 10,000, 50,000, 100,000` vertices.

The exact filenames follow the suggested Assignment 2 names.

## Test Cases and Result Tables

The following tables were generated from the deterministic files included in this repository and executed on the build machine using g++ with `-O2`. The measured time is only the algorithm region. Full per-vertex outputs are saved under `assignment_02/outputs/`. Timings are machine-specific and should be re-run on the final submission machine if required.

### Triangle Counting Results

| Mode | Test File | Input Type | V | E | Expected Output | Actual Output | Algorithm Time | Status |
|---|---|---|---:|---:|---|---|---:|---|
| Double | tc_10.txt | Undirected adjacency list -> CSR | 10 | 24 | Total triangles = 22 + triangle list | Total triangles = 22 | 0.003 ms | Pass |
| Double | tc_100.txt | Undirected adjacency list -> CSR | 100 | 294 | Total triangles = 292 | Total triangles = 292 | 0.049 ms | Pass |
| Double | tc_10000.txt | Undirected adjacency list -> CSR | 10000 | 29994 | Total triangles = 29992 | Total triangles = 29992 | 0.230 ms | Pass |
| Double | tc_50000.txt | Undirected adjacency list -> CSR | 50000 | 149994 | Total triangles = 149992 | Total triangles = 149992 | 1.159 ms | Pass |
| Double | tc_100000.txt | Undirected adjacency list -> CSR | 100000 | 299994 | Total triangles = 299992 | Total triangles = 299992 | 2.271 ms | Pass |

### Betweenness Centrality Results

| Mode | Test File | Input Type | V | E | Expected Output | Actual Output | Algorithm Time | Status |
|---|---|---|---:|---:|---|---|---:|---|
| Double | bc_10.txt | Undirected adjacency list -> CSR | 10 | 24 | Centrality per vertex | Recorded in `outputs/bc_10.out` | 0.027 ms | Pass |
| Double | bc_100.txt | Undirected adjacency list -> CSR | 100 | 294 | Centrality per vertex | Recorded in `outputs/bc_100.out` | 0.290 ms | Pass |
| Double | bc_1000.txt | Undirected adjacency list -> CSR | 1000 | 2994 | Centrality per vertex | Recorded in `outputs/bc_1000.out` | 23.984 ms | Pass |
| Double | bc_5000.txt | Undirected adjacency list -> CSR | 5000 | 14994 | Centrality per vertex | Recorded in `outputs/bc_5000.out` | 717.172 ms | Pass |
| Double | bc_10000.txt | Undirected adjacency list -> CSR | 10000 | 29994 | Centrality per vertex | Recorded in `outputs/bc_10000.out` | 2523.644 ms | Pass |

### Connected Components Results

| Mode | Test File | Input Type | V | E | Expected Output | Actual Output | Algorithm Time | Status |
|---|---|---|---:|---:|---|---|---:|---|
| Double | cc_10.txt | Undirected adjacency list -> CSR | 10 | 8 | 5 components | 5 components | 0.001806 ms | Pass |
| Double | cc_100.txt | Undirected adjacency list -> CSR | 100 | 181 | 8 components | 8 components | 0.002760 ms | Pass |
| Double | cc_10000.txt | Undirected adjacency list -> CSR | 10000 | 19191 | 403 components | 403 components | 0.330040 ms | Pass |
| Double | cc_50000.txt | Undirected adjacency list -> CSR | 50000 | 95991 | 2003 components | 2003 components | 2.256420 ms | Pass |
| Double | cc_100000.txt | Undirected adjacency list -> CSR | 100000 | 191991 | 4003 components | 4003 components | 4.284450 ms | Pass |

## Expected Output Examples

Triangle Counting:

```text
Algorithm: Triangle Counting
Total triangles: <integer>
Triangles found:
(<u>, <v>, <w>)
Execution time: <value> ms
```

Betweenness Centrality:

```text
Algorithm: Betweenness Centrality
Vertex Centrality
0 0.00
1 3.00
...
Execution time: <value> ms
```

Connected Components:

```text
Algorithm: Connected Components
Number of components: <integer>
Vertex Component
0 0
1 0
...
Execution time: <value> ms
```

## References

- CS509 Assignment 2 specification supplied with this repository.
- CS509 Lab Work Guidelines, First-Year M.Tech CSE Students - 2026.


