add_executable(reserve_queue-ut reserve_queue_test.cpp)

target_compile_options(reserve_queue-ut PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(reserve_queue-ut PRIVATE GTest::gtest_main
                                               GTest::gmock_main
                                               clinic-lib
                                               doctor-lib
                                               person-lib
                                               reserve_queue-lib
                                               test_utils-lib
                                               visit-lib)

include(GoogleTest)
gtest_discover_tests(reserve_queue-ut)
