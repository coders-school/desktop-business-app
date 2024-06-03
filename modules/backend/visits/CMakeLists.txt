set(VISITS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/VisitCollection.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/visit/Visit.cpp
)

add_library(visits-lib STATIC ${VISITS_SOURCES})

target_compile_options(visits-lib PRIVATE -Werror -Wall -Wextra -pedantic -Wunused -Wshadow -Wold-style-cast
                                          -Wconversion -Wdangling-pointer)

target_link_libraries(visits-lib PUBLIC common-lib
)

target_include_directories(visits-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# install created lib in our own libraries directory
install(TARGETS visits-lib
        ARCHIVE DESTINATION ${OWN_LIBRARIES_DIR})
# copy include files to our own libraries directory
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION ${OWN_LIBRARIES_DIR}/include
        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
