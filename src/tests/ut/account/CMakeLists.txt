add_executable(account-ut account_test.cpp)

target_compile_options(account-ut PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(account-ut GTest::gtest_main
                                  product-lib
                                  account-lib)

include(GoogleTest)
gtest_discover_tests(account-ut)
