add_subdirectory(model)
add_subdirectory(view_model)

add_executable(${PROJECT_NAME}
  ${PROJECT_SOURCE_DIR}/bindings/imgui_impl_glfw.cpp
  ${PROJECT_SOURCE_DIR}/bindings/imgui_impl_opengl3.cpp
  ${PROJECT_SOURCE_DIR}/bindings/imgui_impl_glfw.h
  ${PROJECT_SOURCE_DIR}/bindings/imgui_impl_opengl3.h
  main.cpp
  $<TARGET_OBJECTS:ModelLib>
  $<TARGET_OBJECTS:ViewModelLib>
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    CONAN_PKG::imgui
    CONAN_PKG::glew
    CONAN_PKG::glfw
    CONAN_PKG::glm
)
