set(UT_SOURCES ut/login/login_test.cpp
               ut/receptionist/receptionist_test.cpp
               ut/receptionist/shift_test.cpp
               ut/visit/treatment_test.cpp
               ut/visit/visit_test.cpp
)
# NOTE: similar set for INTEGRATION_SOURCES to be done when tests apear

include(GoogleTest)

add_executable(${PROJECT_NAME}-tests ${UT_SOURCES})

target_compile_options(${PROJECT_NAME}-tests PRIVATE -Werror -Wall -Wextra -pedantic)

target_link_libraries(${PROJECT_NAME}-tests PRIVATE
                                            GTest::gtest_main
                                            doctor-lib
                                            login-lib
                                            person-lib
                                            receptionist-lib
                                            visit-lib
)

set(CTEST_BINARY_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_test(NAME ${PROJECT_NAME}-tests COMMAND ${PROJECT_NAME}-tests WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
