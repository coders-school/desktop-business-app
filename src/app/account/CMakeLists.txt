add_library(account-lib account.cpp)

target_link_libraries(account-lib PUBLIC encrypt-lib)
target_compile_options(account-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_include_directories(account-lib PUBLIC .) 
