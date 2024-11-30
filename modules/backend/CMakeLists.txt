cmake_minimum_required(VERSION 3.23)
project(desktop-business-app-backend)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(EXTERNAL_LIBRARIES_DIR ${PROJECT_SOURCE_DIR}/../../external_libraries/)
set(OWN_LIBRARIES_DIR ${PROJECT_SOURCE_DIR}/../../libs/)

include(installation_rules.cmake)

add_subdirectory(calendar)
add_subdirectory(clinic)
add_subdirectory(common)
add_subdirectory(patients)
add_subdirectory(proto)
add_subdirectory(serializer)
add_subdirectory(visits)
add_subdirectory(warehouse)

option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Set properties for all targets
get_property(all_targets DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY BUILDSYSTEM_TARGETS)
foreach(target ${all_targets})
    set_target_properties(${target} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    )
endforeach()

