
include(FindProtobuf)
find_package(Protobuf REQUIRED 3.21.0)
include_directories(${PROTOBUF_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS
    staff.proto
    personal_data.proto
    specialization.proto
    sex.proto
    allergen.proto
    treatment_state.proto
    treatment.proto)

add_library(proto ${PROTO_HDRS} ${PROTO_SRCS})

target_include_directories(proto PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS proto
    ARCHIVE DESTINATION ${OWN_LIBRARIES_DIR})
