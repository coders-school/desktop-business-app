set(UT_SOURCES ut/receptionist/shift_test.cpp
               ut/visit/visit_test.cpp)
# NOTE: similar set for INTEGRATION_SOURCES to be done when tests apear

include(GoogleTest)

add_executable(${PROJECT_NAME}-all-tests ${UT_SOURCES})

target_compile_options(${PROJECT_NAME}-all-tests PRIVATE -Werror -Wall -Wextra -pedantic)

target_link_libraries(${PROJECT_NAME}-all-tests PRIVATE
                                                GTest::gtest_main
                                                doctor
                                                person
                                                receptionist
                                                visit
)

set(CTEST_BINARY_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_test(NAME ${PROJECT_NAME}-tests COMMAND ${PROJECT_NAME}-all-tests WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

