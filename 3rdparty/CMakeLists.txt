
add_library(ImGuiFileDialog OBJECT
    ImGuiFileDialog/ImGuiFileDialog.cpp
)

target_link_libraries(ImGuiFileDialog
    PUBLIC
        CONAN_PKG::imgui
        # CONAN_PKG::glew
)

target_include_directories(ImGuiFileDialog
    PUBLIC
        ${CMAKE_SOURCE_DIR}/ImGuiFileDialog
)
