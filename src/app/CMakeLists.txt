# qt_standard_project_setup()

add_subdirectory(calendar)
add_subdirectory(clinic)
add_subdirectory(doctor)
add_subdirectory(login)
add_subdirectory(patient)
add_subdirectory(person)
add_subdirectory(proto)
add_subdirectory(receptionist)
add_subdirectory(reserve_queue)
add_subdirectory(visit)
add_subdirectory(product)
add_subdirectory(room)
add_subdirectory(medicine)
add_subdirectory(equipment)
add_subdirectory(warehouse)

qt_add_executable(${PROJECT_NAME} main.cpp
                                  mainwindow.cpp
                                  mainwindow.ui
                                  mainwindow.h)


target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets
                                              calendar-lib
                                              clinic-lib
                                              doctor-lib
                                              login-lib
                                              equipment-lib
                                              medicine-lib
                                              person-lib
                                              product-lib
                                              proto-lib
                                              receptionist-lib
                                              reserve_queue-lib
                                              room-lib
                                              warehouse-lib
                                              visit-lib)

target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -pedantic)
