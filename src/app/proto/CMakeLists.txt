message(${Protobuf_VERSION})
include_directories(${Protobuf_INCLUDE_DIRS})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS clinic.proto)

add_library(proto-lib ${PROTO_SRCS} ${PROTO_HDRS})
target_compile_options(proto-lib PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(proto-lib PRIVATE product-lib ${PROTOBUF_LIBRARY} )
target_include_directories(proto-lib PUBLIC .)
