add_executable(basic_construction-test basic_construction_test.cpp)

target_compile_options(basic_construction-test PRIVATE -Werror -Wall -Wextra -pedantic)

target_include_directories(basic_construction-test PRIVATE ${OWN_LIBS_INCLUDE_DIR})


# Link against backend libs
target_link_libraries(basic_construction-test PRIVATE
                                              gtest_main
                                              ${CLINIC_LIB}
                                              ${COMMON_LIB}
                                              ${PATIENTS_LIB}
                                              ${SERIALIZER_LIB}
                                              ${VISITS_LIB}
                                              ${WAREHOUSE_LIB}
)

gtest_discover_tests(basic_construction-test)
