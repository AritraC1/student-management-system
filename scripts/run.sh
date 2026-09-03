#!/bin/bash

# run.sh — build and run the student-management-system project
#
# Usage:
#   ./scripts/run.sh          build + run
#   ./scripts/run.sh build    build only
#   ./scripts/run.sh clean    remove build artifacts

set -euo pipefail

# ---- config ----

# Prefer Homebrew GCC (needed if any file still uses bits/stdc++.h),
# fall back to g++ / clang++ if it's not installed.

if command -v g++-16 &> /dev/null; then
    CXX="g++-16"
elif command -v g++ &> /dev/null; then
    CXX="g++"
else
    CXX="clang++"
fi

STD="c++17"
SRC_DIR="src"
BUILD_DIR="build"
BIN_NAME="student_management_system"

# ---- paths ----

# Resolve project root as the parent of this script's directory
# (assumes this script lives in scripts/)
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
 
cd "$ROOT_DIR"

# ---- clean ----

if [[ "${1:-}" == "clean" ]]; then
    echo "Cleaning build directory..."
    rm -rf "$BUILD_DIR"
    echo "Done."
    exit 0
fi

# ---- build ----

mkdir -p "$BUILD_DIR"

echo "Using compiler: $CXX"
echo "Collecting source files from $SRC_DIR ..."

# Find every .cpp file under src/ recursively
while IFS= read -r -d '' file; do
    SOURCES+=("$file")
done < <(find "$SRC_DIR" -name "*.cpp" -print0)

if [[ ${#SOURCES[@]} -eq 0 ]]; then
    echo "No .cpp files found under $SRC_DIR. Aborting."
    exit 1
fi

printf '  %s\n' "${SOURCES[@]}"

echo "Compiling..."
"$CXX" -std="$STD" -Wall -Wextra -I"$SRC_DIR" "${SOURCES[@]}" -o "$BUILD_DIR/$BIN_NAME"
 
echo "Build succeeded: $BUILD_DIR/$BIN_NAME"

# ---- run ----

if [[ "${1:-}" == "build" ]]; then
    exit 0
fi
 
echo "Running..."
echo "----------------------------------------"
"./$BUILD_DIR/$BIN_NAME"
