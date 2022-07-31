
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/bindings)

### sort of integration tests ###

add_executable(ImguiTest
    ${PROJECT_SOURCE_DIR}/bindings/imgui_impl_glfw.cpp
    ${PROJECT_SOURCE_DIR}/bindings/imgui_impl_opengl3.cpp
    ${PROJECT_SOURCE_DIR}/bindings/imgui_impl_glfw.h
    ${PROJECT_SOURCE_DIR}/bindings/imgui_impl_opengl3.h
    imgui_test.cpp
)
target_link_libraries(ImguiTest
  PUBLIC
    CONAN_PKG::imgui
    CONAN_PKG::glew
    CONAN_PKG::glfw
)

# add_test(NAME ImguiTests
#         COMMAND  ImguiTest
#         WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
#### regular tests ####

add_subdirectory(model)
add_subdirectory(view_model)

add_executable(UnitTests
  $<TARGET_OBJECTS:ModelTestLib>
  $<TARGET_OBJECTS:ModelLib>
  $<TARGET_OBJECTS:ViewModelTestLib>
  $<TARGET_OBJECTS:ViewModelLib>
  gtest.cpp
)

target_link_libraries(UnitTests
  PUBLIC
    CONAN_PKG::imgui
    CONAN_PKG::glm
    CONAN_PKG::gtest
)

add_test(NAME  UnitTests
        COMMAND  UnitTests
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
