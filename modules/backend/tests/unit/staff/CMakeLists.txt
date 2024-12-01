set(STAFF_INCLUDE_DIRS ${OWN_LIBS_INCLUDE_DIR}/clinic)
set(STAFF_INCLUDE_LIBS
    gtest_main
    gmock_main
    clinic-lib
    mocks-lib
)

_add_test(ReceptionistTests receptionist/ReceptionistTests.cpp INCLUDE_DIRS ${STAFF_INCLUDE_DIRS} INCLUDE_LIBS ${STAFF_INCLUDE_LIBS})
_add_test(DoctorTests doctor/DoctorTests.cpp INCLUDE_DIRS ${STAFF_INCLUDE_DIRS} INCLUDE_LIBS ${STAFF_INCLUDE_LIBS})
