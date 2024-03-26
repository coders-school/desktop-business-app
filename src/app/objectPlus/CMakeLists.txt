add_library(objectPlus-lib objectPlus.cpp)

target_compile_options(objectPlus-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_include_directories(objectPlus-lib PUBLIC .)