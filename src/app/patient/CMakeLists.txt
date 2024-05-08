add_library(patient-lib patient.cpp allergen.cpp)

target_compile_options(patient-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(patient-lib PRIVATE clinic-lib
                                          person-lib
                                          visit-lib)
target_include_directories(patient-lib PUBLIC .)
