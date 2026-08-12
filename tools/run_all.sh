#!/usr/bin/env bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
A2="$ROOT/assignment_02"
mkdir -p "$A2/outputs"
make -C "$A2" all
for n in 10 100 10000 50000 100000; do "$A2/triangle_driver" "$A2/tests/tc_${n}.txt" > "$A2/outputs/tc_${n}.out"; done
for n in 10 100 1000 5000 10000; do "$A2/bc_driver" "$A2/tests/bc_${n}.txt" > "$A2/outputs/bc_${n}.out"; done
for n in 10 100 10000 50000 100000; do "$A2/cc_driver" "$A2/tests/cc_${n}.txt" > "$A2/outputs/cc_${n}.out"; done
echo "All Assignment 2 tests completed. Results are in assignment_02/outputs/"
