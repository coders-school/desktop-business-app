add_library(medicine-lib medicine.cpp)

target_compile_options(medicine-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(medicine-lib PRIVATE product-lib)
target_include_directories(medicine-lib PUBLIC .)
