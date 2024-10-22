#!/bin/bash

# This script is used to clean the build directory then build the backend and application
rm -rf build_backend

rm -rf build_app

set -e

mkdir build_backend && cd build_backend

cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=OFF ../modules/backend/

cmake --build . --parallel --clean-first -- -j2

mkdir ../build_app && cd ../build_app

cmake ../modules/app/

cmake --build . --parallel --clean-first -- -j2
