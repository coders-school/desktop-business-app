# cmake_minimum_required(VERSION 3.23)
# project(desktop-business-app-tests)

# set(CMAKE_CXX_STANDARD 20)

# TODO: adjust both after new structure is finalized
# set(BACKEND_LIB_DIRECTORY  ${PROJECT_SOURCE_DIR}/../backend/)
# set(OWN_LIB_DIRECTORY  ${PROJECT_SOURCE_DIR}/../../own_libraries)
message(STATUS "BACKEND_LIB_DIRECTORY: ${BACKEND_LIB_DIRECTORY}")
# message(STATUS "OWN_LIB_DIRECTORY: ${OWN_LIB_DIRECTORY}")

# test binaries will be in this directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/../../bin)

include(install_gtest.cmake)

include(GoogleTest)
enable_testing()

# Set vars to the path to the libraries installed from backend
# set(CLINIC_LIB ${OWN_LIB_DIRECTORY}/libclinic-lib.a)
# set(COMMON_LIB ${OWN_LIB_DIRECTORY}/libcommon-lib.a)
# set(PATIENTS_LIB ${OWN_LIB_DIRECTORY}/libpatients-lib.a)
# set(SERIALIZER_LIB ${OWN_LIB_DIRECTORY}/libserializer-lib.a)
# set(VISITS_LIB ${OWN_LIB_DIRECTORY}/libvisits-lib.a)
# set(WAREHOUSE_LIB ${OWN_LIB_DIRECTORY}/libwarehouse-lib.a)

# Set the path to the headers installed from backend
# set(OWN_LIBS_INCLUDE_DIR ${BACKEND_LIB_DIRECTORY})

# Global settings for memory checks
include(CTest)
set(MEMORYCHECK_COMMAND_OPTIONS
                "--trace-children=yes --leak-check=full --show-reachable=yes --read-var-info=yes --track-origins=yes --error-limit=no -error-exitcode=1")
set(MEMORYCHECK_COMMAND valgrind)

add_subdirectory(unit)
add_subdirectory(integration)
