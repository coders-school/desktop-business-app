#!/bin/bash

# Find all .cpp, .h, and .hpp files and format them using clang-format
find ./ -name '*.cpp' -or -name '*.hpp' | xargs clang-format --verbose -style=file -i
