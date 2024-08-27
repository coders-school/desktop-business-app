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

# install library in our own libraries directory
install(TARGETS patients-lib
        ARCHIVE DESTINATION ${OWN_LIBRARIES_DIR})
# copy include files to our own libraries directory
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION ${OWN_LIBRARIES_DIR}/include
        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
