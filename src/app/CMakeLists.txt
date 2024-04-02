qt_standard_project_setup()

add_subdirectory(doctor)
add_subdirectory(equipment)
add_subdirectory(login)
add_subdirectory(medicine)
add_subdirectory(person)
add_subdirectory(product)
add_subdirectory(receptionist)
add_subdirectory(room)
add_subdirectory(visit)
add_subdirectory(warehouse)

qt_add_executable(${PROJECT_NAME} main.cpp
                                  mainwindow.cpp
                                  mainwindow.ui
                                  mainwindow.h)


target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets
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

target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -pedantic)
