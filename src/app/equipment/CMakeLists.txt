add_library(equipment-lib equipment.cpp)

target_include_directories(equipment-lib PRIVATE ../product)
target_compile_options(equipment-lib PRIVATE -Werror -Wall -Wextra -pedantic)
