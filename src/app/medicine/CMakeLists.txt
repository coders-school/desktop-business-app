add_library(medicine-lib medicine.cpp)

target_include_directories(medicine-lib PRIVATE ../product)
target_compile_options(medicine-lib PRIVATE -Werror -Wall -Wextra -pedantic)
