set(UT_SOURCES ut/login/login_test.cpp
               ut/patient/allergen_test.cpp
               ut/clinic/clinic_test.cpp
               ut/doctor/doctor_test.cpp
               ut/patient/patient_test.cpp
               ut/receptionist/receptionist_test.cpp
               ut/receptionist/shift_test.cpp
               ut/reserve_queue/reserve_queue_test.cpp
               ut/visit/treatment_test.cpp
               ut/visit/visit_test.cpp
               ut/calendar/calendar_test.cpp
)
# NOTE: similar set for INTEGRATION_SOURCES to be done when tests apear

include(GoogleTest)

add_subdirectory(test_utils)

add_executable(${PROJECT_NAME}-tests ${UT_SOURCES})

target_compile_options(${PROJECT_NAME}-tests PRIVATE -Werror -Wall -Wextra -pedantic)

target_link_libraries(${PROJECT_NAME}-tests PRIVATE
                                            GTest::gtest_main
                                            GTest::gmock_main
                                            clinic-lib
                                            doctor-lib
                                            login-lib
                                            patient-lib
                                            person-lib
                                            receptionist-lib
                                            reserve_queue-lib
                                            test_utils-lib
                                            visit-lib
                                            calendar-lib
)

set(CTEST_BINARY_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_test(NAME ${PROJECT_NAME}-tests COMMAND ${PROJECT_NAME}-tests WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(ut/warehouse)
add_subdirectory(ut/medicine)
add_subdirectory(ut/equipment)
add_subdirectory(ut/reserve_queue)
