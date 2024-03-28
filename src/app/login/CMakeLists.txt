add_library(login-lib login.cpp)

target_compile_options(login-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_include_directories(login-lib PUBLIC .) 
target_link_libraries(login-lib PRIVATE OpenSSL::SSL)
