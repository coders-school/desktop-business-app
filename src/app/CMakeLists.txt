qt_standard_project_setup()

add_subdirectory(clinic)
add_subdirectory(doctor)
add_subdirectory(login)
add_subdirectory(patient)
add_subdirectory(person)
add_subdirectory(receptionist)
add_subdirectory(visit)
add_subdirectory(product)
add_subdirectory(room)
add_subdirectory(medicine)
add_subdirectory(equipment)
add_subdirectory(warehouse)

qt_add_executable(${PROJECT_NAME} main.cpp)


target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Gui
                                              Qt6::Quick
                                              clinic-lib
                                              doctor-lib
                                              login-lib
                                              equipment-lib
                                              medicine-lib
                                              person-lib
                                              product-lib
                                              receptionist-lib
                                              room-lib
                                              warehouse-lib
                                              visit-lib)

qt_add_qml_module(${PROJECT_NAME}
                    URI desktop-business-app
                    VERSION 1.0
                    QML_FILES main.qml)

target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -pedantic)
