cmake_minimum_required (VERSION 3.12)

project (hello)

# Initialize CMake library for KasperskyOS SDK.
include (platform)
initialize_platform (FORCE_STATIC)

find_package (vfs REQUIRED)
include_directories (${vfs_INCLUDE})

find_package (precompiled_vfs REQUIRED)
include_directories (${precompiled_vfs_INCLUDE})

add_subdirectory (hello)
add_subdirectory (einit)
