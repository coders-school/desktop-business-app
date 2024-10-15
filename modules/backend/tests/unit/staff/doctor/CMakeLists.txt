add_executable(DoctorTests DoctorTests.cpp)

target_compile_options(DoctorTests PRIVATE -Werror -Wall -Wextra -pedantic)

target_include_directories(DoctorTests PRIVATE ${OWN_LIBS_INCLUDE_DIR}/clinic)

target_link_libraries(DoctorTests PRIVATE
    gtest_main
    clinic-lib
    mocks-lib
)

add_test(NAME DoctorTests COMMAND DoctorTests  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
