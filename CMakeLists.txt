cmake_minimum_required(VERSION 3.23)
project(desktop-business-app)

set(CMAKE_CXX_STANDARD 20)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${SRC_DIR}/includes)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)

set(SRC ${SRC_DIR}/main.cpp
        ${SRC_DIR}/mainwindow.cpp)
set(TESTS ${TEST_DIR}/unit-tests.cpp)

find_package(GTest REQUIRED)
enable_testing()

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_executable(${PROJECT_NAME}-ut ${TESTS})
qt_add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(${PROJECT_NAME}-ut PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(${PROJECT_NAME}-ut GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)
