add_executable(BirthDateTests BirthDateTests.cpp)

target_compile_options(BirthDateTests PRIVATE -Werror -Wall -Wextra -pedantic)

target_include_directories(BirthDateTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/common)

target_link_libraries(BirthDateTests PRIVATE gtest_main common-lib)

add_test(NAME BirthDateTests COMMAND BirthDateTests WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
