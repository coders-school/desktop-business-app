add_library(file_manager-lib file_manager.cpp)

target_compile_options(file_manager-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_include_directories(file_manager-lib PUBLIC .)
