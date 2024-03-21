cmake_minimum_required(VERSION 3.23)
project(desktop-business-app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

find_package(GTest REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
enable_testing()

add_subdirectory(src/app)
add_subdirectory(src/tests)
