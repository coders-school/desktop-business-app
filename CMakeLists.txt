cmake_minimum_required(VERSION 3.23)
project(desktop-business-app)

set(CMAKE_CXX_STANDARD 20)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${SRC_DIR}/includes)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)

set(SRC ${SRC_DIR}/main.cpp)
set(TESTS ${TEST_DIR}/unit-tests.cpp)


find_package(GTest REQUIRED)
enable_testing()

add_executable(${PROJECT_NAME} ${SRC})
add_executable(${PROJECT_NAME}-ut ${TESTS})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
target_link_libraries(${PROJECT_NAME}-ut GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)
