qt_standard_project_setup()

qt_add_executable(${PROJECT_NAME} main.cpp
                                  mainwindow.cpp
                                  mainwindow.ui
                                  mainwindow.h)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
