set(CALENDAR_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/TimeSlot.cpp
)

add_library(calendar-lib STATIC ${CALENDAR_SOURCES})

target_compile_options(calendar-lib PRIVATE -Werror -Wall -Wextra -pedantic -Wunused -Wshadow -Wold-style-cast
                                          -Wconversion )

target_link_libraries(calendar-lib PUBLIC visits-lib)

target_include_directories(calendar-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(calendar-lib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
)
