#!/bin/bash

# TODO fix 

# Find the build directory
BUILD_TESTS_DIR=$(find . -type d -name "build")

if [ -z "$BUILD_TESTS_DIR" ]
then
    echo "build directory not found"
    exit 1
fi


cd "$BUILD_TESTS_DIR"

# Run ctest for the summary output
GTEST_COLOR=1 ctest

# Run ctest again for the detailed output of failed tests only
GTEST_COLOR=1 ctest --output-on-failure | awk '/\[  FAILED  \]/,/(\d+ ms)/'
