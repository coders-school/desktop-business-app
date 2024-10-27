add_executable(SerializerHelperTests SerializerHelperTests.cpp)

target_compile_options(SerializerHelperTests PRIVATE -Werror -Wall -Wextra -pedantic)

target_include_directories(SerializerHelperTests PRIVATE ${OWN_LIBS_INCLUDE_DIR}/serializer)

target_link_libraries(SerializerHelperTests PRIVATE
    gtest_main
    serializer-lib
)

add_test(NAME SerializerHelperTests COMMAND SerializerHelperTests  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
