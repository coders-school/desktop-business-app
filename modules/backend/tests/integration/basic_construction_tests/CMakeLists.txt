add_executable(basic_construction-test basic_construction_test.cpp)

target_compile_options(basic_construction-test PRIVATE -Werror -Wall -Wextra -pedantic)

message(STATUS "CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}")

# set(aa /home/lnx/cs/desktop-business-app/build/proto)
set(PROTO_DIR ${PROJECT_SOURCE_DIR}/../../build/proto)
target_include_directories(basic_construction-test PRIVATE
    ${OWN_LIBS_INCLUDE_DIR}/common
    ${OWN_LIBS_INCLUDE_DIR}/clinic
    ${OWN_LIBS_INCLUDE_DIR}/patients
    ${OWN_LIBS_INCLUDE_DIR}/serializer
    ${OWN_LIBS_INCLUDE_DIR}/visits
    ${OWN_LIBS_INCLUDE_DIR}/warehouse
    ${PROTO_DIR}
)

target_link_libraries(basic_construction-test PRIVATE
    gtest_main
    clinic-lib
    common-lib
    patients-lib
    serializer-lib
    visits-lib
    warehouse-lib
)

add_test(NAME basic_construction-test COMMAND basic_construction-test
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
