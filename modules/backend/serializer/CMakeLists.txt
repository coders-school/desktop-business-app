set(SERIALIZER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/SerializerHelper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Serializer.cpp
)

add_library(serializer-lib STATIC ${SERIALIZER_SOURCES})

target_compile_options(serializer-lib PRIVATE -Werror -Wall -Wextra -pedantic -Wunused -Wshadow -Wold-style-cast -Wconversion)

target_link_libraries(serializer-lib PUBLIC
    common-lib
    clinic-lib
    protobuff
)

target_include_directories(serializer-lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
set_target_properties(serializer-lib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
)
