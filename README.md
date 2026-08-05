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
