add_library(mocks-lib INTERFACE)

target_compile_options(mocks-lib INTERFACE -Werror -Wall -Wextra -pedantic)

target_include_directories(mocks-lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                                            ${OWN_LIBS_INCLUDE_DIR})

target_link_libraries(mocks-lib INTERFACE gmock)
