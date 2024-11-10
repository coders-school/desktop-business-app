#!/bin/bash

rm -rf build_app

set -e

mkdir build_app && cd build_app

cmake ../modules/app/

cmake --build . --parallel --clean-first -- -j2