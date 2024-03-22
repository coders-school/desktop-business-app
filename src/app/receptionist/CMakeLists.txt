add_library(receptionist-lib shift.cpp receptionist.cpp)

target_compile_options(receptionist-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_include_directories(receptionist-lib PUBLIC .)
