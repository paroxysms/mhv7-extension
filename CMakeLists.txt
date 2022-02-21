cmake_minimum_required(VERSION 3.21)
project(mhv7-extension-rs)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

enable_language(Rust)
include(CMakeCargo)

add_subdirectory(rs)

include_directories("include")

add_library(mhv7-extension-rs SHARED library.cpp)
target_link_libraries(mhv7-extension-rs ${CMAKE_SOURCE_DIR}\\libs\\hackpro.lib)
target_link_libraries(mhv7-extension-rs rs ws2_32 userenv Bcrypt)