#!/bin/bash

# Find the build_tests directory
BUILD_TESTS_DIR=$(find . -type d -name "build_tests")

if [ -z "$BUILD_TESTS_DIR" ]
then
    echo "build_tests directory not found"
    exit 1
fi

# Navigate to the build_tests directory, run ctest, and navigate back
cd "$BUILD_TESTS_DIR" && ctest && cd -
