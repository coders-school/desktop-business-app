include(installation_rules.cmake)

add_subdirectory(clinic)
add_subdirectory(common)
add_subdirectory(patients)
add_subdirectory(serializer)
add_subdirectory(visits)
add_subdirectory(warehouse)
add_subdirectory(proto)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()

# Set properties for all targets
get_property(all_targets DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY BUILDSYSTEM_TARGETS)
foreach(target ${all_targets})
    set_target_properties(${target} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    )
endforeach()

