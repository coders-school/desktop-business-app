qt_add_executable(${PROJECT_NAME} main.cpp
                                  mainwindow.cpp
                                  mainwindow.ui
                                  mainwindow.h
                                  erweqrw.h erweqrw.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -pedantic)
