set(TESTS unit-tests.cpp)
set(SOURCES ../app/doctor/doctor.cpp ../app/person/person.cpp ../app/visit/visit.cpp)
set(CMAKE_OSX_SYSROOT "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk")


add_executable(${PROJECT_NAME}-ut ${TESTS} ${SOURCES})

target_compile_options(${PROJECT_NAME}-ut PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(${PROJECT_NAME}-ut GTest::gtest_main)

include_directories(../app/doctor)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)

