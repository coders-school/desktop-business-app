add_library(room-lib room.cpp)

target_compile_options(room-lib PRIVATE -Werror -Wall -Wextra -pedantic)
<<<<<<< HEAD
target_link_libraries(room-lib PRIVATE visit-lib
                                       warehouse-lib)
target_include_directories(room-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
=======
target_link_libraries(room-lib PRIVATE visit-lib)
target_include_directories(room-lib PUBLIC .)
>>>>>>> d349a39 (Update README.md (#66))
