add_library(visit-lib visit.cpp
                      treatment.cpp)

target_compile_options(visit-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(visit-lib PRIVATE clinic-lib
                                        doctor-lib
                                        patient-lib)
target_include_directories(visit-lib PUBLIC .)
