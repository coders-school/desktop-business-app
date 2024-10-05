set(COMMON_LIB_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/enumerations/allergen/Allergen.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/enumerations/sex/Sex.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/enumerations/specialization/Specialization.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/enumerations/treatment/Treatment.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/enumerations/treatment_state/TreatmentState.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/personal_data/PersonalData.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/personal_data/pesel/Pesel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/validators/PeselValidator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/file_manager/FileManager.cpp
)

add_library(common-lib STATIC ${COMMON_LIB_SOURCES})

target_compile_options(common-lib PRIVATE -Werror -Wall -Wextra -pedantic -Wunused -Wshadow -Wold-style-cast
                                          -Wconversion )


target_include_directories(common-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# # install created lib in our own libraries directory
# install(TARGETS common-lib
#         ARCHIVE DESTINATION ${OWN_LIBRARIES_DIR})
# # copy include files to our own libraries directory
# install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION ${OWN_LIBRARIES_DIR}/include
#         FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
set_target_properties(common-lib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
)