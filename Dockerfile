FROM alpine:latest as BUILD
ENV PROJECT_NAME=desktop-business-app

# Install required packages: g++, cmake, make
RUN apk update && apk add --no-cache g++ cmake make
RUN apk add --no-cache gtest-dev

# Copy source code and tests
WORKDIR /app
COPY src /app/src
COPY tests /app/tests
COPY CMakeLists.txt .

# Build and run tests
RUN cmake -S . -B build && cmake --build build

# Run tests
RUN /app/build/${PROJECT_NAME}-ut

# Build the final image
FROM alpine:latest as FINAL
ENV PROJECT_NAME=desktop-business-app

RUN apk update && apk add --no-cache g++ cmake make
WORKDIR /app
COPY --from=BUILD /app/build/${PROJECT_NAME} /app/build/${PROJECT_NAME}

# RUN PROGRAM
ENTRYPOINT /app/build/${PROJECT_NAME}
