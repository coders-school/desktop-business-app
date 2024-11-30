set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../bin)

include(install_gtest.cmake)

include(GoogleTest)
enable_testing()

include(CTest)
set(MEMORYCHECK_COMMAND valgrind)
set(MEMORYCHECK_COMMAND_OPTIONS
    "--trace-children=yes 
    --gen-suppressions=all
    --leak-check=full
    --show-reachable=yes
    --read-var-info=yes
    --track-origins=yes
    --error-limit=no 
    --child-silent-after-fork=yes
    -error-exitcode=1")
set(COMMON_COMPILE_OPTIONS -Werror -Wall -Wextra -pedantic)
set(COMMON_LIBS gtest_main )

function(_add_test TEST_NAME TEST_SRC)
    set(multiValueArgs INCLUDE_DIRS INCLUDE_LIBS)
    cmake_parse_arguments(ARGS "" "" "${multiValueArgs}" ${ARGN})

    add_executable(${TEST_NAME} ${TEST_SRC})
    target_compile_options(${TEST_NAME} PRIVATE ${COMMON_COMPILE_OPTIONS})
    target_include_directories(${TEST_NAME} PRIVATE ${ARGS_INCLUDE_DIRS})
    target_link_libraries(${TEST_NAME} PRIVATE ${COMMON_LIBS} ${ARGS_INCLUDE_LIBS})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME} WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    message(STATUS "Added test: ${TEST_NAME}")
endfunction()

add_subdirectory(unit)
add_subdirectory(integration)
add_subdirectory(mocks)
