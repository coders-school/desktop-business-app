add_executable(StaffTests StaffTests.cpp)

target_compile_options(StaffTests PRIVATE -Werror -Wall -Wextra -pedantic)

target_include_directories(StaffTests PRIVATE ${OWN_LIBS_INCLUDE_DIR})

# Link against backend libs
target_link_libraries(StaffTests PRIVATE
    gtest_main
    gmock_main
    ${CLINIC_LIB}
    ${COMMON_LIB}
)

add_test(NAME StaffTests COMMAND StaffTests WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
