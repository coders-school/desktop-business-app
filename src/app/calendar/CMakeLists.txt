add_library(calendar-lib calendar.cpp connector.cpp)

target_compile_options(calendar-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_include_directories(calendar-lib PUBLIC .)