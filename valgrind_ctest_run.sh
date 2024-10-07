#!/bin/bash

# Find the build directory
BUILD_TESTS_DIR=$(find . -type d -name "build")

if [ -z "$BUILD_TESTS_DIR" ]; then
    echo "build directory not found"
    exit 1
fi

cd "$BUILD_TESTS_DIR"

# Ensure Valgrind is installed
if ! command -v valgrind &> /dev/null; then
    echo "Valgrind is not installed. Please install it and try again."
    exit 1
fi

# Run CTest with Valgrind memory check
GTEST_COLOR=1 ctest -T memcheck --output-on-failure

# Directory where Valgrind logs are stored
LOG_DIR="./Testing/Temporary"

# Check if the log directory exists
if [ ! -d "$LOG_DIR" ]; then
    echo "Log directory $LOG_DIR does not exist."
    exit 1
fi

# Initialize a flag to indicate if any memory errors were found
found_errors=0

# Process each log file
for log_file in ${LOG_DIR}/MemoryChecker.*.log; do
    # Check if the log file exists
    if [ ! -f "$log_file" ]; then
        echo "Log file $log_file does not exist."
        continue
    fi

    # Check if the log file contains any errors
    if grep -q "ERROR SUMMARY: 0 errors" "$log_file"; then
        # No action needed if no errors are found
        true
    else
        # Set the flag to indicate that errors were found
        found_errors=1
        # Break the loop as we only need to know if there are any errors
        break
    fi
done

# Return an error code if any memory errors were found
if [ "$found_errors" -eq 1 ]; then
    echo "Memory errors detected."
    exit 1
else
    echo "No memory errors detected."
fi