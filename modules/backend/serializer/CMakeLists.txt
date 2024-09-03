set(SERIALIZER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/SerializerHelper.cpp
)

add_library(serializer-lib STATIC ${SERIALIZER_SOURCES})

# Add the necessary compiler options
target_compile_options(serializer-lib PRIVATE -Werror -Wall -Wextra -pedantic -Wunused -Wshadow -Wold-style-cast -Wconversion)

# Link against the proto library (which has the necessary headers)
target_link_libraries(serializer-lib PUBLIC
    clinic-lib
    proto  # Link to the proto target
)

# Include directories
target_include_directories(serializer-lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${OWN_LIBRARIES_DIR}/include/proto  
)

# Install the serializer library
install(TARGETS serializer-lib
    ARCHIVE DESTINATION ${OWN_LIBRARIES_DIR}/lib
)

# Install any additional headers related to the serializer
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION ${OWN_LIBRARIES_DIR}/include
    FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
