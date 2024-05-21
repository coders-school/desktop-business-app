set(UT_SOURCES ut/calendar/calendar_test.cpp
               ut/clinic/clinic_test.cpp
               ut/data_file_manager/data_file_manager_test.cpp
               ut/doctor/doctor_test.cpp
               ut/equipment/equipment_test.cpp
               integration/integration_tests.cpp
               ut/login/login_test.cpp
               ut/medicine/medicine_test.cpp
               ut/patient/allergen_test.cpp
               ut/patient/patient_test.cpp
               ut/person/person_test.cpp
               ut/person/gender_test.cpp
               ut/receptionist/receptionist_test.cpp
               ut/receptionist/shift_test.cpp
               ut/reserve_queue/reserve_queue_test.cpp
               ut/visit/status_test.cpp
               ut/visit/treatment_test.cpp
               ut/visit/visit_test.cpp
               ut/warehouse/warehouse_test.cpp
)
# NOTE: similar set for INTEGRATION_SOURCES to be done when tests apear

include(GoogleTest)

add_subdirectory(test_utils)

add_executable(${PROJECT_NAME}-tests ${UT_SOURCES})

target_compile_options(${PROJECT_NAME}-tests PRIVATE -Werror -Wall -Wextra -pedantic)

target_link_libraries(${PROJECT_NAME}-tests PRIVATE
                                            GTest::gtest_main
                                            GTest::gmock_main
                                            calendar-lib
                                            clinic-lib
                                            data_file_manager-lib
                                            doctor-lib
                                            equipment-lib
                                            login-lib
                                            medicine-lib
                                            patient-lib
                                            person-lib
                                            product-lib
                                            receptionist-lib
                                            reserve_queue-lib
                                            room-lib
                                            test_utils-lib
                                            visit-lib
                                            warehouse-lib
)

set(CTEST_BINARY_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_test(NAME ${PROJECT_NAME}-tests COMMAND ${PROJECT_NAME}-tests WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
