add_executable(medicine-ut medicine-ut.cpp)

target_compile_options(medicine-ut PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(medicine-ut GTest::gtest_main
                                  product-lib
                                  medicine-lib)

include(GoogleTest)
gtest_discover_tests(medicine-ut)
