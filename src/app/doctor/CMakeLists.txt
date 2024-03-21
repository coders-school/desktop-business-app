add_library(doctor-lib doctor.cpp)

target_compile_options(doctor-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_include_directories(doctor-lib PUBLIC .)
