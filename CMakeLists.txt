cmake_minimum_required(VERSION 3.21)

# Set CUDA architecture before project()
set(CMAKE_CUDA_ARCHITECTURES "native")

project(
    GPUtils
    VERSION 0.1.0
    DESCRIPTION "Short description"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX CUDA
)

set(CMAKE_CXX_STANDARD 17)

# Include your cmake files
include(cmake/prelude.cmake)
include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    GPUtils_lib OBJECT
    source/lib.cpp
    source/CUDA-kernels/add.cu        # Add CUDA kernel to the library here
)

target_include_directories(
    GPUtils_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(GPUtils_lib PUBLIC cxx_std_17)

find_package(fmt REQUIRED)
target_link_libraries(GPUtils_lib PRIVATE fmt::fmt)

# ---- Declare executable ----

add_executable(GPUtils_exe source/main.cpp)

set_property(TARGET GPUtils_exe PROPERTY OUTPUT_NAME GPUtils)

target_compile_features(GPUtils_exe PRIVATE cxx_std_17)

target_link_libraries(GPUtils_exe PRIVATE GPUtils_lib)

add_executable(GPUtils::exe ALIAS GPUtils_exe)

# ---- Install rules ----

