set(PATIENTS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/PatientCollection.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PatientsFactory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/patient/allergens/Allergens.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/patient/Patient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/patient/treatments/Treatments.cpp
)

add_library(patients-lib STATIC ${PATIENTS_SOURCES})

target_compile_options(patients-lib PRIVATE -Werror -Wall -Wextra -pedantic -Wunused -Wshadow -Wold-style-cast
                                            -Wconversion )

target_link_libraries(patients-lib PUBLIC common-lib)

target_include_directories(patients-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(patients-lib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
)
