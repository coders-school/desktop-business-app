add_executable(warehouse-ut warehouse-ut.cpp)

target_compile_options(warehouse-ut PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(warehouse-ut GTest::gtest_main warehouse-lib product-lib)

include(GoogleTest)
gtest_discover_tests(warehouse-ut)
