qt_standard_project_setup()

add_subdirectory(doctor)
add_subdirectory(person)
add_subdirectory(receptionist)
add_subdirectory(visit)

qt_add_executable(${PROJECT_NAME} main.cpp
                                  mainwindow.cpp
                                  mainwindow.ui
                                  mainwindow.h)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets
                                              doctor-lib
                                              person-lib
                                              receptionist-lib
                                              visit-lib
)
target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -pedantic)

add_subdirectory(product)
add_subdirectory(medicine)
add_subdirectory(equipment)
add_subdirectory(warehouse)
target_link_libraries(${PROJECT_NAME} PRIVATE product-lib
                                              medicine-lib
                                              equipment-lib
                                              warehouse-lib)
