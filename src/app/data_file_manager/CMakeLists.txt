add_library(data_file_manager-lib data_file_manager.cpp)

target_link_libraries(data_file_manager-lib PUBLIC clinic-lib file_manager-lib doctor-lib patient-lib visit-lib receptionist-lib warehouse-lib proto-lib)
target_compile_options(data_file_manager-lib PRIVATE -Werror -Wall -Wextra -pedantic -lprotobuf -lpthread)
target_include_directories(data_file_manager-lib PUBLIC .)
