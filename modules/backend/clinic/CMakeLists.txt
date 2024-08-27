set(CLINIC_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Clinic.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/room/Room.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/staff/doctor/Doctor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/staff/Staff.cpp
)

add_library(clinic-lib STATIC ${CLINIC_SOURCES})

target_compile_options(clinic-lib PRIVATE -Werror -Wall -Wextra -pedantic -Wunused -Wshadow -Wold-style-cast
                                          -Wconversion )

target_link_libraries(clinic-lib PUBLIC
                                 common-lib
                                 warehouse-lib
)

target_include_directories(clinic-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# install created lib in our own libraries directory
install(TARGETS clinic-lib
        ARCHIVE DESTINATION ${OWN_LIBRARIES_DIR})

# copy include files to our own libraries directory
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION ${OWN_LIBRARIES_DIR}/include
        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
