#!/bin/bash

# Find the build_tests directory
BUILD_TESTS_DIR=$(find . -type d -name "build_tests")

if [ -z "$BUILD_TESTS_DIR" ]
then
    echo "build_tests directory not found"
    exit 1
fi


cd "$BUILD_TESTS_DIR"

# Run ctest for the summary output
GTEST_COLOR=1 ctest

# Run ctest again for the detailed output of failed tests only
GTEST_COLOR=1 ctest --output-on-failure | awk '/\[  FAILED  \]/,/(\d+ ms)/'
