set(CLINIC_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Clinic.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/room/Room.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/staff/doctors/Doctor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/staff/receptionists/Receptionist.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/staff/Staff.cpp
)

add_library(clinic-lib STATIC ${CLINIC_SOURCES})

target_compile_options(clinic-lib PRIVATE -Werror -Wall -Wextra -pedantic -Wunused -Wshadow -Wold-style-cast
    -Wconversion)

target_link_libraries(clinic-lib PUBLIC
    common-lib
    warehouse-lib
)

target_include_directories(clinic-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(clinic-lib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
)
