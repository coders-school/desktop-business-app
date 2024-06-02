set(SERIALIZER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Serializer.cpp
)

add_library(serializer-lib STATIC ${SERIALIZER_SOURCES})

target_compile_options(serializer-lib PRIVATE -Werror -Wall -Wextra -pedantic)
#TODO: fill when serializer developed
# target_link_libraries(serializer-lib PUBLIC )

target_include_directories(serializer-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# install library in our own libraries directory
install(TARGETS serializer-lib
        ARCHIVE DESTINATION ${OWN_LIBRARIES_DIR})
# copy include files to our own libraries directory
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION ${OWN_LIBRARIES_DIR}/include
        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
