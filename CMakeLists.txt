cmake_minimum_required(VERSION 3.2.1 FATAL_ERROR)
set(PROJECT_NAME "Imgui-Mvp")
project(${PROJECT_NAME})

include(build/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

message("Building ${PROJECT_NAME}")
option(BUILD_TESTS "Build tests" ON)

enable_testing()

if(BUILD_TESTS)
  add_subdirectory(tests)
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/bindings)
file(GLOB_RECURSE SOURCES_LIST "src/*.cpp")

add_executable(${PROJECT_NAME} 
  ${SOURCES_LIST}
  bindings/imgui_impl_glfw.cpp
  bindings/imgui_impl_opengl3.cpp
  bindings/imgui_impl_glfw.h
  bindings/imgui_impl_opengl3.h
)

set_target_properties(
  ${PROJECT_NAME} PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED YES
                             CXX_EXTENSIONS NO)

target_link_libraries(${PROJECT_NAME} 
  PUBLIC
    CONAN_PKG::imgui
    CONAN_PKG::glew
    CONAN_PKG::glfw
)

target_compile_definitions(${PROJECT_NAME}
  PUBLIC 
    IMGUI_IMPL_OPENGL_LOADER_GLEW
)
