#!/bin/bash

# Exit script on first error
set -e

# Check if the external_libraries directory does not exist
if [ ! -d "external_libraries" ]; then
  # If it does not exist, create it
  mkdir external_libraries
fi

# Check if the own_libraries directory does not exist
if [ ! -d "own_libraries" ]; then
  # If it does not exist, create it
  mkdir own_libraries
fi

# Clean the build library
rm -rf build

# Create the build directory and navigate into it
mkdir build && cd build

# Configure with CMake
cmake -DCMAKE_BUILD_TYPE=Debug ../modules/backend/

# Build the target and install backend libs and headers to own_libraries
cmake --build . --parallel --target install