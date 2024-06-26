# EXPERIMENTAl: installing specific versions of libraries to be used by our project
include(ExternalProject)

####### fixed version of protobuf for project
set(PROTOBUF_PREFIX "${EXTERNAL_LIBRARIES_DIR}/protobuf")
set(PROTOBUF_BASE_URL "https://github.com/protocolbuffers/protobuf/releases/download")
set(RELEASE_TAG "v21.0")
set(PROTOBUF_VERSION "3.21.0")

ExternalProject_Add(protobuf
    URL "${PROTOBUF_BASE_URL}/${RELEASE_TAG}/protobuf-cpp-${PROTOBUF_VERSION}.tar.gz"
    PREFIX ${PROTOBUF_PREFIX}
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=<INSTALL_DIR>
    BUILD_COMMAND ${MAKE}
    DOWNLOAD_EXTRACT_TIMESTAMP true
)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${PROTOBUF_PREFIX})
