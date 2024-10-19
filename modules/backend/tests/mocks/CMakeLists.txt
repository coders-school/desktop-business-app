add_library(mocks-lib STATIC DoctorMock/DoctorMock.cpp
                             ReceptionistMock/ReceptionistMock.cpp)

target_compile_options(mocks-lib PRIVATE -Werror -Wall -Wextra -pedantic)

target_include_directories(mocks-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                     PRIVATE ${OWN_LIBS_INCLUDE_DIR})