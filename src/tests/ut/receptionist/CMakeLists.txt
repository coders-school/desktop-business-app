set(TEST_NAME shift_test)
set(THIS_TEST_NAME ${PROJECT_NAME}-${TEST_NAME})
add_executable(${THIS_TEST_NAME} ${TEST_NAME}.cpp)

target_link_libraries(${THIS_TEST_NAME} GTest::gtest_main shift)
include(GoogleTest)
gtest_discover_tests(${THIS_TEST_NAME})
