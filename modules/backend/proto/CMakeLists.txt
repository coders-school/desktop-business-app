
include(FindProtobuf)
find_package(Protobuf REQUIRED 3.21.0)
include_directories(${PROTOBUF_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS
    allergen.proto
    doctor.proto
    personal_data.proto
    receptionist.proto
    staff.proto
    specialization.proto
    treatment.proto
    treatment_state.proto)

add_library(proto ${PROTO_SRCS} ${PROTO_HDRS})

target_include_directories(proto PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(proto PUBLIC ${PROTOBUF_LIBRARIES})

install(TARGETS proto
    ARCHIVE DESTINATION ${OWN_LIBRARIES_DIR}/lib)

install(FILES ${PROTO_HDRS} DESTINATION ${OWN_LIBRARIES_DIR}/include/proto)
install(FILES ${PROTO_SRCS}  DESTINATION ${OWN_LIBRARIES_DIR}/include/proto)

