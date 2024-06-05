add_executable(SexTests SexTests.cpp)

target_compile_options(SexTests PRIVATE -Werror -Wall -Wextra -pedantic)

target_include_directories(SexTests PRIVATE ${OWN_LIBS_INCLUDE_DIR})

# Link against backend libs
target_link_libraries(SexTests PRIVATE
    gtest_main
    ${COMMON_LIB}
)

gtest_discover_tests(SexTests)
