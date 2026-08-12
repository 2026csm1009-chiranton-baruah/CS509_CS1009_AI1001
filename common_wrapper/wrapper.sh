#!/usr/bin/env bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
A2="$ROOT/assignment_02"

echo "CS509 Assignment 2 - Buddy Task"
echo "1) Triangle Counting"
echo "2) Betweenness Centrality"
echo "3) Connected Components"
echo "4) Build all"
echo "5) Run all test files for one algorithm"
echo "0) Exit"
read -r -p "Select: " choice

case "$choice" in
  1) make -C "$A2" triangle; read -r -p "Input file: " f; "$A2/triangle_driver" "$f" ;;
  2) make -C "$A2" bc; read -r -p "Input file: " f; "$A2/bc_driver" "$f" ;;
  3) make -C "$A2" cc; read -r -p "Input file: " f; "$A2/cc_driver" "$f" ;;
  4) make -C "$A2" all ;;
  5)
    read -r -p "Algorithm (tc/bc/cc): " alg
    make -C "$A2" all
    case "$alg" in
      tc) for f in "$A2"/tests/tc_*.txt; do echo "===== $f ====="; "$A2/triangle_driver" "$f"; done ;;
      bc) for f in "$A2"/tests/bc_*.txt; do echo "===== $f ====="; "$A2/bc_driver" "$f"; done ;;
      cc) for f in "$A2"/tests/cc_*.txt; do echo "===== $f ====="; "$A2/cc_driver" "$f"; done ;;
      *) echo "Unknown algorithm"; exit 2 ;;
    esac
    ;;
  0) exit 0 ;;
  *) echo "Invalid choice"; exit 2 ;;
esac
