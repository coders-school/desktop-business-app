add_library(person-lib person.cpp gender.cpp)

target_compile_options(person-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_include_directories(person-lib PUBLIC .)
