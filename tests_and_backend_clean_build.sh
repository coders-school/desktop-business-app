#!/bin/bash

# Clean the build library
rm -rf build

# Exit script on first error
set -e

# Create the build directory and navigate into it
mkdir build && cd build

# Configure backend with CMake
cmake -DCMAKE_BUILD_TYPE=Debug ../modules/backend/

# Build the target and install backend libs and headers to own_libraries
cmake --build . --parallel --target install

# go back to main app directory
cd ..

# Check if the build_tests directory does not exist
if [ ! -d "build_tests" ]; then
  # If it does not exist, create it
  mkdir build_tests
fi

# Change directory to build_tests
cd build_tests

# Cclean build_tests directory
# Check if the current directory is build_tests before removing everything
if [ $(basename "$PWD") == "build_tests" ]; then
  # Remove everything in the current directory
  rm -rf *
fi

# configure tests target with CMake
cmake -DCMAKE_BUILD_TYPE=Debug ../modules/tests/

# Build the tests target
cmake --build . --parallel
