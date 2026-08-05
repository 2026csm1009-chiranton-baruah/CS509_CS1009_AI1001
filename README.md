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

# BFS Output

For each implementation:

- Resultant traversal
- Execution time (milliseconds)

---

# Task 2 — CSR Graph Representation

The graph is initially supplied as an adjacency list and converted into Compressed Sparse Row (CSR) format.

The implementation supports:

- Unweighted graphs
- Weighted graphs

---

# Graph Input Format

First line:

```
Vertices Edges Weighted
```

where

- Weighted = 0 → Unweighted
- Weighted = 1 → Weighted

---

## Unweighted Example

```
5 6 0
0 1 2
1 0 3
2 0 4
3 1
4 2
```

---

## Weighted Example

```
5 6 1
0 1 5 2 3
1 2 8
2 3 1
3 4 2
4
```

Each edge is stored as

```
destination weight
```

---

# CSR Output

The program displays

- Number of vertices
- Number of edges
- Row Pointer array
- Column Index array
- Weight array (weighted graphs only)
- CSR conversion time

---

# Test Cases

The following graph sizes were prepared according to the assignment specification.

| Test File | Vertices | Graph Type |
|------------|---------:|------------|
| csr_10.txt | 10 | Connected sparse graph |
| csr_100.txt | 100 | Chain graph |
| csr_10000.txt | 10000 | Sparse graph |
| csr_50000.txt | 50000 | Sparse graph |
| csr_100000.txt | 100000 | Sparse graph |

The following GEMM test files are included.

| Test File | Matrix Size |
|------------|------------|
| gemm_test_01.txt | 2 x 3 and 3 x 2 |
| gemm_test_02.txt | 99 x 99 and 99 x 99 |
| gemm_test_03.txt | 70 x 80 and 80 x 90 |
| gemm_test_04.txt | 20 x 25 and 25 x 30 |
| gemm_test_05.txt | 200 x 205 and 205 x 210 |

---

# Performance Measurement

Execution times are measured using

```
std::chrono::high_resolution_clock
```

Reported timings are in milliseconds.

| Test File | Vertices (V) | Edges (E) | Graph Type | Conversion Time (ms) |
|-----------|-------------:|----------:|------------|---------------------:|
| csr_10.txt | 10 | 12 | Connected Sparse | 0.005234 |
| csr_100.txt | 100 | 99 | Chain | 0.003838 |
| csr_10000.txt | 10000 | 9999 | Chain | 0.275331 |
| csr_50000.txt | 50000 | 49999 | Chain | 24.5791 |
| csr_100000.txt | 100000 | 99999 | Chain | 24.6112 |

| Test File | Matrix Size | Simple GEMM (ms) | Blocked GEMM (ms) |
|-----------|------------:|-----------------:|------------------:|
| gemm_test_01.txt | 2 x 3 and 3 x 2 | 0.002371 | 0.001847 |
| gemm_test_02.txt | 99 x 99 and 99 x 99 | 0.815193 | 0.938234 |
| gemm_test_03.txt | 70 x 80 and 80 x 90 | 0.937587 | 0.96552 |
| gemm_test_04.txt | 20 x 25 and 25 x 30 | 0.026406 | 0.041937 |
| gemm_test_05.txt | 200 x 205 and 205 x 210 | 6.77056 | 12.4146| 

---

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
