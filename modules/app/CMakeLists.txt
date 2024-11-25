cmake_minimum_required(VERSION 3.23)
project(desktop-business-app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../bin)
link_directories(${PROJECT_SOURCE_DIR}/../../libs/)

find_package(Qt6 REQUIRED COMPONENTS Quick Gui)

qt_standard_project_setup()

qt_add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Gui
                                              Qt6::Quick
                                              libclinic-lib.a
                                              libcommon-lib.a
                                              libpatients-lib.a
                                              libprotobuff.a
                                              libserializer-lib.a
                                              libvisits-lib.a
                                              libwarehouse-lib.a)

qt_add_qml_module(${PROJECT_NAME}
                    URI desktop-business-app
                    VERSION 1.0
                    QML_FILES main.qml 
                    mainMenu.qml
                    loginScreen.qml)