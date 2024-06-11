add_executable(PatientCollectionTests PatientCollectionTest.cpp)

target_compile_options(PatientCollectionTests PRIVATE -Werror -Wall -Wextra -pedantic)

target_include_directories(PatientCollectionTests PRIVATE ${OWN_LIBS_INCLUDE_DIR})

# Link against backend libs
target_link_libraries(PatientCollectionTests PRIVATE
    gtest_main
    ${COMMON_LIB}
)

add_test(NAME PatientCollectionTests COMMAND PatientCollectionTests WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})