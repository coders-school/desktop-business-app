add_library(equipment-lib equipment.cpp)

target_link_libraries(equipment-lib PRIVATE product-lib)
target_compile_options(equipment-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_include_directories(equipment-lib PUBLIC .)
