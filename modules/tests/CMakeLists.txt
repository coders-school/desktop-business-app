cmake_minimum_required(VERSION 3.23)
project(desktop-business-app-tests)

set(CMAKE_CXX_STANDARD 20)

# TODO: adjust both after new structure is finalized
set(BACKEND_LIB_DIRECTORY  ${PROJECT_SOURCE_DIR}/../../own_libraries)
# test binaries will be in this directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/../../bin)

include(install_gtest.cmake)

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

# Global settings for memory checks
include(CTest)
set(MEMORYCHECK_COMMAND_OPTIONS
                "--trace-children=yes --leak-check=full --show-reachable=yes --read-var-info=yes --track-origins=yes --error-limit=no -error-exitcode=1")
set(MEMORYCHECK_COMMAND valgrind)

add_subdirectory(unit_tests)
add_subdirectory(integration_tests)
