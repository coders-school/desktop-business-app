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

add_subdirectory(unit)
add_subdirectory(integration)
