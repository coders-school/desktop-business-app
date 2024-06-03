cmake_minimum_required(VERSION 3.23)
project(desktop-business-app-tests)

set(CMAKE_CXX_STANDARD 20)

# TODO: adjust both after new structure is finalized
set(BACKEND_LIB_DIRECTORY  ${PROJECT_SOURCE_DIR}/../../own_libraries)
# test binaries will be in this directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/../../bin)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

include(GoogleTest)
enable_testing()

# Set vars to the path to the libraries installed from backend
set(CLINIC_LIB ${BACKEND_LIB_DIRECTORY}/libclinic-lib.a)
set(COMMON_LIB ${BACKEND_LIB_DIRECTORY}/libcommon-lib.a)
set(PATIENTS_LIB ${BACKEND_LIB_DIRECTORY}/libpatients-lib.a)
set(SERIALIZER_LIB ${BACKEND_LIB_DIRECTORY}/libserializer-lib.a)
set(VISITS_LIB ${BACKEND_LIB_DIRECTORY}/libvisits-lib.a)
set(WAREHOUSE_LIB ${BACKEND_LIB_DIRECTORY}/libwarehouse-lib.a)

# Set the path to the headers installed from backend
set(OWN_LIBS_INCLUDE_DIR ${BACKEND_LIB_DIRECTORY}/include)

add_subdirectory(unit_tests)
add_subdirectory(integration_tests)
