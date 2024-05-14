add_library(warehouse-lib warehouse.cpp)

target_compile_options(warehouse-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(warehouse-lib PUBLIC product-lib
                                           clinic-lib)
target_include_directories(warehouse-lib PUBLIC .)
