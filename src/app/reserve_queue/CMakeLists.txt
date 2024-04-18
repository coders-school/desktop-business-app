add_library(reserve_queue-lib reserve_queue.cpp)

target_compile_options(reserve_queue-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_include_directories(reserve_queue-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
