add_library(product-lib product.cpp)

target_compile_options(product-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_include_directories(product-lib PUBLIC .)
