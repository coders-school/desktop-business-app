set(TEST_NAME material_test)

add_executable(${PROJECT_NAME}-${TEST_NAME} ${TEST_NAME}.cpp)

target_link_libraries(${PROJECT_NAME}-${TEST_NAME} GTest::gtest_main material)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-${TEST_NAME})
