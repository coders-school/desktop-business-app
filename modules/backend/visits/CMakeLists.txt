set(VISITS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/VisitCollection.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/visit/Visit.cpp
)

add_library(visits-lib STATIC ${VISITS_SOURCES})

target_compile_options(visits-lib PRIVATE -Werror -Wall -Wextra -pedantic -Wunused -Wshadow -Wold-style-cast
                                          -Wconversion )

target_link_libraries(visits-lib PUBLIC common-lib patients-lib clinic-lib)

target_include_directories(visits-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(visits-lib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
)
