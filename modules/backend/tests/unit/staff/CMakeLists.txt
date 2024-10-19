cmake_minimum_required(VERSION 3.10)
project(ClinicTests)

set(COMMON_COMPILE_OPTIONS -Werror -Wall -Wextra -pedantic)
set(COMMON_INCLUDE_DIRS ${OWN_LIBS_INCLUDE_DIR}/clinic)
set(COMMON_LIBS
    gtest_main
    gmock_main
    clinic-lib
    mocks-lib
)

function(add_staff_test TEST_NAME TEST_SRC)
    add_executable(${TEST_NAME} ${TEST_SRC})
    target_compile_options(${TEST_NAME} PRIVATE ${COMMON_COMPILE_OPTIONS})
    target_include_directories(${TEST_NAME} PRIVATE ${COMMON_INCLUDE_DIRS})
    target_link_libraries(${TEST_NAME} PRIVATE ${COMMON_LIBS})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME} WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endfunction()

add_staff_test(ReceptionistTests receptionist/ReceptionistTests.cpp)

add_staff_test(DoctorTests doctor/DoctorTests.cpp)
