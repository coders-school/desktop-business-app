qt_standard_project_setup()

qt_add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Gui
                                              Qt6::Quick)

qt_add_qml_module(${PROJECT_NAME}
                    URI desktop-business-app
                    VERSION 1.0
                    QML_FILES main.qml)
