
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/bindings)

add_executable(UnitTests
    ${PROJECT_SOURCE_DIR}/bindings/imgui_impl_glfw.cpp
    ${PROJECT_SOURCE_DIR}/bindings/imgui_impl_opengl3.cpp
    ${PROJECT_SOURCE_DIR}/bindings/imgui_impl_glfw.h
    ${PROJECT_SOURCE_DIR}/bindings/imgui_impl_opengl3.h
    test.cpp
)

set_target_properties(
    UnitTests PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED YES
                             CXX_EXTENSIONS NO)

target_link_libraries(UnitTests
  PUBLIC
    CONAN_PKG::imgui
    CONAN_PKG::glew
    CONAN_PKG::glfw
)

add_test(NAME  Tests 
        COMMAND  UnitTests
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})