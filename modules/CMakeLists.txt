add_subdirectory(backend)
add_subdirectory(app)

target_link_libraries(${PROJECT_NAME} PRIVATE libclinic-lib.a
                                              libcommon-lib.a
                                              libpatients-lib.a
                                              libprotobuff.a
                                              libserializer-lib.a
                                              libvisits-lib.a
                                              libwarehouse-lib.a)
