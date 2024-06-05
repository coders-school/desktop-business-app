add_executable(PeselValidatorTests PeselValidatorTests.cpp)

target_compile_options(PeselValidatorTests PRIVATE -Werror -Wall -Wextra -pedantic)

target_include_directories(PeselValidatorTests PRIVATE ${OWN_LIBS_INCLUDE_DIR})

target_include_directories(PeselValidatorTests PRIVATE ${CLINIC_INCLUDE_DIR})

# Link against backend libs
target_link_libraries(PeselValidatorTests PRIVATE
    gtest_main
    ${COMMON_LIB}
)

gtest_discover_tests(PeselValidatorTests)
