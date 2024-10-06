#!/bin/bash

# This script is used to clean the build directory then build the backend and run tests
rm -rf build

set -e

mkdir build && cd build

cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON ../modules/backend/

cmake --build . --parallel --clean-first -- -j2

ctest --output-on-failure