cmake_minimum_required(VERSION 3.23)
project(desktop-business-app-backend)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)

#TODO: adjust both when we have final version of structure of our project
set(EXTERNAL_LIBRARIES_DIR ${PROJECT_SOURCE_DIR}/../../external_libraries/)
set(OWN_LIBRARIES_DIR ${PROJECT_SOURCE_DIR}/../../own_libraries/)

include(installation_rules.cmake)

# include(FindProtobuf)
# find_package(Protobuf REQUIRED 3.21.0)
# include_directories(${PROTOBUF_INCLUDE_DIR})
# include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(clinic)
add_subdirectory(common)
add_subdirectory(patients)
add_subdirectory(serializer)
add_subdirectory(visits)
add_subdirectory(warehouse)
add_subdirectory(proto)

