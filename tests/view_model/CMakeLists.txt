add_library(ViewModelTestLib OBJECT
  SceneTest.cpp
)

target_link_libraries(ViewModelTestLib
  PUBLIC
    CONAN_PKG::imgui
    CONAN_PKG::glm
    CONAN_PKG::gtest
)

target_include_directories(ViewModelTestLib
  PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/tests
)