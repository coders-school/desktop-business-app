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

# This script is used to clean the build directory then build the backend and run tests
rm -rf build

mkdir build && cd build

cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=1 ..

cmake --build . --parallel --clean-first -- -j2

ctest --output-on-failure