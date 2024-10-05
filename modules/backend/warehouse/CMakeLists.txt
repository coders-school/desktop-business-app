set(WAREHOUSE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Warehouse.cpp
)

add_library(warehouse-lib STATIC ${WAREHOUSE_SOURCES})

target_compile_options(warehouse-lib PRIVATE -Werror -Wall -Wextra -pedantic -Wunused -Wshadow -Wold-style-cast
    -Wconversion)

target_include_directories(warehouse-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(warehouse-lib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
)
