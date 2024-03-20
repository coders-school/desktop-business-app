add_library(visit-lib visit.cpp)

target_compile_options(visit-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_include_directories(visit-lib PUBLIC .)
