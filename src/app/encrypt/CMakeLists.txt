add_library(encrypt-lib encrypt.cpp)

target_compile_options(encrypt-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_include_directories(encrypt-lib PUBLIC .) 
target_link_libraries(encrypt-lib PRIVATE OpenSSL::SSL)
