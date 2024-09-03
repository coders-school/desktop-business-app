set(SERIALIZER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/SerializerHelper.cpp
)

add_library(serializer-lib STATIC ${SERIALIZER_SOURCES})

target_compile_options(serializer-lib PRIVATE -Werror -Wall -Wextra -pedantic -Wunused -Wshadow -Wold-style-cast -Wconversion)

target_link_libraries(serializer-lib PUBLIC
    clinic-lib
    proto  
)

target_include_directories(serializer-lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${OWN_LIBRARIES_DIR}/include/proto  
)

install(TARGETS serializer-lib
    ARCHIVE DESTINATION ${OWN_LIBRARIES_DIR}/lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION ${OWN_LIBRARIES_DIR}/include
    FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
