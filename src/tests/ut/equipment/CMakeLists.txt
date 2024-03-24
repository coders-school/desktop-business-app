add_executable(equipment-ut equipment-ut.cpp)

target_compile_options(equipment-ut PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(equipment-ut GTest::gtest_main
                                   product-lib
                                   equipment-lib)

include(GoogleTest)
gtest_discover_tests(equipment-ut)
