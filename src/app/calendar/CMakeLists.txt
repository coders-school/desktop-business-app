add_library(calendar-lib calendar.cpp year.cpp month.cpp day.cpp day_name.cpp)

target_compile_options(calendar-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_include_directories(calendar-lib PUBLIC .)