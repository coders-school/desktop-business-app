FROM alpine:latest as BUILD
ENV PROJECT_NAME=desktop-business-app

# Install required packages: g++, cmake, make
RUN apk update && apk add --no-cache g++ cmake make
RUN apk add --no-cache gtest-dev
RUN apk add qt6-qtbase-dev

# Copy source code and tests
WORKDIR /app
COPY . /app

# Build and run tests
RUN cmake -S . -B build && cmake --build build

# Run tests
RUN /app/bin/${PROJECT_NAME}-ut

# Build the final image
FROM alpine:latest as FINAL
ENV PROJECT_NAME=desktop-business-app

RUN apk update && apk add --no-cache g++ cmake make
RUN apk add qt6-qtbase-dev
WORKDIR /app
COPY . /app

# RUN PROGRAM
ENTRYPOINT /app/bin/${PROJECT_NAME}
