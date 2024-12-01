set(BASIC_CONSTRUCTION_INCLUDE_DIRS 
    ${OWN_LIBS_INCLUDE_DIR}/common
    ${OWN_LIBS_INCLUDE_DIR}/clinic
    ${OWN_LIBS_INCLUDE_DIR}/patients
    ${OWN_LIBS_INCLUDE_DIR}/serializer
    ${OWN_LIBS_INCLUDE_DIR}/visits
    ${OWN_LIBS_INCLUDE_DIR}/warehouse
    ${PROJECT_SOURCE_DIR}/../../build/proto)

set(BASIC_CONTRUCTION_INCLUDE_LIBS 
    clinic-lib
    common-lib
    patients-lib
    serializer-lib
    visits-lib
    warehouse-lib)

_add_test(basic_construction-test basic_construction_test.cpp
    INCLUDE_DIRS ${BASIC_CONSTRUCTION_INCLUDE_DIRS}
    INCLUDE_LIBS ${BASIC_CONTRUCTION_INCLUDE_LIBS})
