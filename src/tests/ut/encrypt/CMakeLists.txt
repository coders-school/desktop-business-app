add_executable(encrypt-ut encrypt_test.cpp)

target_compile_options(encrypt-ut PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(encrypt-ut GTest::gtest_main
                                  product-lib
                                  encrypt-lib)

include(GoogleTest)
gtest_discover_tests(encrypt-ut)
