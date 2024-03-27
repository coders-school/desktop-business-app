add_library(clinic-lib clinic_facade.cpp)

target_compile_options(clinic-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_include_directories(clinic-lib PUBLIC .)
