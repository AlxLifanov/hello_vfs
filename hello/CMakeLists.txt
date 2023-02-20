project (hello)

# Tools for using NK parser.
include (platform/nk)

# Set compile flags.
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

nk_build_edl_files (hello_edl_files NK_MODULE "hello" EDL "${CMAKE_SOURCE_DIR}/resources/edl/Hello.edl")

add_executable (Hello "src/hello.c")
target_link_libraries (Hello ${vfs_CLIENT_LIB})     # include vfs precompiled client library
add_dependencies (Hello hello_edl_files)
