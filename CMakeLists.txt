cmake_minimum_required(VERSION 3.2.1 FATAL_ERROR)
set(PROJECT_NAME "inventory-prototype")
set(CMAKE_CXX_STANDARD 20)
project(${PROJECT_NAME})

include(build/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

message("Building ${PROJECT_NAME}")
option(BUILD_TESTS "Build tests" ON)

enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/bindings)

if(BUILD_TESTS)
  add_subdirectory(tests)
endif()

add_subdirectory(3rdparty)
add_subdirectory(src)

file(COPY ${CMAKE_SOURCE_DIR}/textures
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
