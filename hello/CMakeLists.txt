project (hello)

# Tools for using NK parser.
include (platform/nk)

# Set compile flags.
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

nk_build_edl_files (hello_edl_files NK_MODULE "hello" EDL "${CMAKE_SOURCE_DIR}/resources/edl/Hello.edl")

add_executable (Hello "src/hello.c")
target_link_libraries (Hello ${vfs_CLIENT_LIB})
add_dependencies (Hello hello_edl_files)
#set_target_properties (Hello PROPERTIES LINK_FLAGS "-no-pie -Ttext 0x00800000")
