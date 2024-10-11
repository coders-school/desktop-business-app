cmake_minimum_required(VERSION 3.23)
project(desktop-business-app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(EXTERNAL_LIBRARIES_DIR ${PROJECT_SOURCE_DIR}/external_libraries/)
set(OWN_LIBRARIES_DIR ${PROJECT_SOURCE_DIR}/libs/)
link_directories(${PROJECT_SOURCE_DIR}/libs)

find_package(Protobuf REQUIRED)
find_package(GTest REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(OpenSSL REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(glog 0.6.0 REQUIRED)

if(BUILD_TESTS)
    enable_testing()
endif()

add_subdirectory(modules)
