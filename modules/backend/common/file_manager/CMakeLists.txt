# set(FILE_MANAGER
#     ${CMAKE_CURRENT_SOURCE_DIR}/FileManager.cpp
# )

# add_library(file_manager_lib STATIC ${FILE_MANAGER})

# target_compile_options(file_manager_lib PRIVATE -Werror -Wall -Wextra -pedantic -Wunused -Wshadow -Wold-style-cast -Wconversion)

# target_link_libraries(file_manager_lib PUBLIC
# )

# install(TARGETS file_manager_lib
#     ARCHIVE DESTINATION ${OWN_LIBRARIES_DIR}
# )

# install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION ${OWN_LIBRARIES_DIR}/include
#     FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
