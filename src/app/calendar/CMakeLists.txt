add_library(calendar-lib calendar.cpp connector.cpp)

target_compile_options(calendar-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(calendar-lib PUBLIC doctor-lib
                                          room-lib)
target_include_directories(calendar-lib PUBLIC .)
