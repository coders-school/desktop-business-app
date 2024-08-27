set(WAREHOUSE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Warehouse.cpp
)

add_library(warehouse-lib STATIC ${WAREHOUSE_SOURCES})


target_compile_options(warehouse-lib PRIVATE -Werror -Wall -Wextra -pedantic -Wunused -Wshadow -Wold-style-cast
                                             -Wconversion )

#TODO: add targets to be linked against when needed
# target_link_libraries(visits-lib PUBLIC
# )

target_include_directories(warehouse-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# install created lib in our own libraries directory
install(TARGETS warehouse-lib
        ARCHIVE DESTINATION ${OWN_LIBRARIES_DIR})
# copy include files to our own libraries directory
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION ${OWN_LIBRARIES_DIR}/include
        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
