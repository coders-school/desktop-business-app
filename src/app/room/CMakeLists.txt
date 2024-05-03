add_library(room-lib room.cpp)

target_compile_options(room-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(room-lib PRIVATE clinic-lib
                                       visit-lib
                                       warehouse-lib)
target_include_directories(room-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
