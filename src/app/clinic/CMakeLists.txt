add_library(clinic-lib clinic_facade.cpp)

target_compile_options(clinic-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(clinic-lib PUBLIC doctor-lib
                                         patient-lib
                                         receptionist-lib
                                         room-lib
                                         visit-lib
                                         calendar-lib)
target_include_directories(clinic-lib PUBLIC .)
