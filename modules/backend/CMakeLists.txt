cmake_minimum_required(VERSION 3.23)
project(desktop-business-app-backend)

set(CMAKE_CXX_STANDARD 20)

#TODO: adjust both when we have final version of structure of our project
set(EXTERNAL_LIBRARIES_DIR ${PROJECT_SOURCE_DIR}/../../external_libraries/)
set(OWN_LIBRARIES_DIR ${PROJECT_SOURCE_DIR}/../../own_libraries/)

# EXPERIMENTAl: installing specific versions of libraries to be used by our project
include(ExternalProject)

####### fixed version of protobuf for project
set(PROTOBUF_PREFIX "${EXTERNAL_LIBRARIES_DIR}/protobuf")
set(PROTOBUF_BASE_URL "https://github.com/protocolbuffers/protobuf/releases/download")
set(RELEASE_TAG "v21.0")
set(PROTOBUF_VERSION "3.21.0")
set(PROTOBUF_PREFIX "${EXTERNAL_LIBRARIES_DIR}/protobuf")
ExternalProject_Add(protobuf
    URL "${PROTOBUF_BASE_URL}/${RELEASE_TAG}/protobuf-cpp-${PROTOBUF_VERSION}.tar.gz"
    PREFIX ${PROTOBUF_PREFIX}
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=<INSTALL_DIR>
    BUILD_COMMAND ${MAKE}
    DOWNLOAD_EXTRACT_TIMESTAMP true
)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${PROTOBUF_PREFIX})

find_package(Protobuf REQUIRED)

add_subdirectory(clinic)
add_subdirectory(common)
add_subdirectory(patients)
add_subdirectory(serializer)
add_subdirectory(visits)
add_subdirectory(warehouse)

