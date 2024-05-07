add_library(doctor-lib doctor.cpp)

target_compile_options(doctor-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(doctor-lib PUBLIC  clinic-lib
                                         person-lib
                                         visit-lib)
target_include_directories(doctor-lib PUBLIC .)
