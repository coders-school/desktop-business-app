add_executable(AllergenTests SpecializationTests.cpp)
add_executable(SexTests SexTests.cpp)
add_executable(SpecializationTests SpecializationTests.cpp)

target_compile_options(AllergenTests PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(SexTests PRIVATE -Werror -Wall -Wextra -pedantic)
target_compile_options(SpecializationTests PRIVATE -Werror -Wall -Wextra -pedantic)

target_include_directories(AllergenTests PRIVATE ${OWN_LIBS_INCLUDE_DIR})
target_include_directories(SexTests PRIVATE ${OWN_LIBS_INCLUDE_DIR})
target_include_directories(SpecializationTests PRIVATE ${OWN_LIBS_INCLUDE_DIR})

# Link against backend libs
target_link_libraries(AllergenTests PRIVATE gtest_main ${COMMON_LIB})
target_link_libraries(SexTests PRIVATE gtest_main ${COMMON_LIB})
target_link_libraries(SpecializationTests PRIVATE gtest_main ${COMMON_LIB})

add_test(NAME AllergenTests COMMAND AllergenTests WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
add_test(NAME SexTests COMMAND SexTests WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
add_test(NAME SpecializationTests COMMAND SpecializationTests WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
