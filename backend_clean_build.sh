#!/bin/bash

# Exit script on first error
set -e

# Check if the external_libraries directory does not exist
if [ ! -d "external_libraries" ]; then
  # If it does not exist, create it
  mkdir external_libraries
fi

# Check if the libs directory does not exist
if [ ! -d "libs" ]; then
  # If it does not exist, create it
  mkdir libs
fi

# Clean the build library
rm -rf build

# Create the build directory and navigate into it
mkdir build && cd build

# Configure with CMake
cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=0 ..

# Build the target and install backend libs and headers to libs
cmake --build . --parallel --clean-first -- -j2
