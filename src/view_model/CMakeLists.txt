add_library(ViewModelLib OBJECT
    Ladder.cpp
    Player.cpp
    Renderable.cpp
    Scene.cpp
    Wall.cpp
)

target_link_libraries(ViewModelLib
  PUBLIC
    CONAN_PKG::imgui
    CONAN_PKG::glm
    CONAN_PKG::stb
    CONAN_PKG::glew
    $<TARGET_OBJECTS:ImGuiFileDialog>
)

target_include_directories(ViewModelLib
  PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/3rdparty
)