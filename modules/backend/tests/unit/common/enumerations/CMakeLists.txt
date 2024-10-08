add_executable(AllergenTests AllergenTests.cpp)
add_executable(SexTests SexTests.cpp)
add_executable(SpecializationTests SpecializationTests.cpp)
add_executable(TreatmentTests TreatmentTests.cpp)
add_executable(TreatmentStateTests TreatmentStateTests.cpp)

set(COMPILE_OPTIONS -Werror -Wall -Wextra -pedantic)

target_compile_options(AllergenTests PRIVATE ${COMPILE_OPTIONS})
target_compile_options(SexTests PRIVATE ${COMPILE_OPTIONS})
target_compile_options(SpecializationTests PRIVATE ${COMPILE_OPTIONS})
target_compile_options(TreatmentTests PRIVATE ${COMPILE_OPTIONS})
target_compile_options(TreatmentStateTests PRIVATE ${COMPILE_OPTIONS})


target_include_directories(AllergenTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(SexTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(SpecializationTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(TreatmentTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(TreatmentStateTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(AllergenTests PRIVATE gtest_main common-lib)
target_link_libraries(SexTests PRIVATE gtest_main common-lib)
target_link_libraries(SpecializationTests PRIVATE gtest_main common-lib)
target_link_libraries(TreatmentTests PRIVATE gtest_main common-lib)
target_link_libraries(TreatmentStateTests PRIVATE gtest_main common-lib)


add_test(NAME AllergenTests COMMAND AllergenTests WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
add_test(NAME SexTests COMMAND SexTests WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
add_test(NAME SpecializationTests COMMAND SpecializationTests WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
add_test(NAME TreatmentTests COMMAND TreatmentTests WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
add_test(NAME TreatmentStateTests COMMAND TreatmentStateTests WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
