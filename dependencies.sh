#!/bin/sh

apt update

apt install -y \
    libgtest-dev libgmock-dev \
    cmake make g++ \
    qt6-base-dev \
    libgl1-mesa-dev \
    libssl-dev \
    nlohmann-json3-dev \
    libgoogle-glog-dev \
    protobuf-compiler libprotobuf-dev \
    git \
    valgrind
