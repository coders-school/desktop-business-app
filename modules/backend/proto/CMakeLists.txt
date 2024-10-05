include(FindProtobuf)
find_package(Protobuf REQUIRED 3.21.0)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS
    allergen.proto
    doctor.proto
    personal_data.proto
    receptionist.proto
    staff.proto
    specialization.proto
    treatment.proto
    treatment_state.proto)


add_library(protobuff ${PROTO_SRCS} ${PROTO_HDRS})
target_compile_options(protobuff PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(protobuff PUBLIC ${PROTOBUF_LIBRARIES})
message(STATUS "PROTOBUF_LIBRARIES ${PROTOBUF_LIBRARIES}")
target_include_directories(protobuff PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

set_target_properties(protobuff PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${OWN_LIBRARIES_DIR}
)
# install(TARGETS protobuff
#     ARCHIVE DESTINATION ${OWN_LIBRARIES_DIR})

# install(FILES ${PROTO_HDRS} DESTINATION ${OWN_LIBRARIES_DIR}/include/proto)
# install(FILES ${PROTO_SRCS} DESTINATION ${OWN_LIBRARIES_DIR}/include/proto)

message(STATUS "PROTOBUF_INCLUDE_DIR ${PROTOBUF_INCLUDE_DIR}")
include_directories(${PROTOBUF_INCLUDE_DIR})
message(STATUS "CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}")
include_directories(${CMAKE_CURRENT_BINARY_DIR})