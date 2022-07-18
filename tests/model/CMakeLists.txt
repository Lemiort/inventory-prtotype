add_library(ModelTestLib OBJECT
    IconTest.cpp
    LadderTest.cpp
    PlayerTest.cpp
    RenderableTest.cpp
    SceneTest.cpp
    WallTest.cpp
)

target_link_libraries(ModelTestLib
  PUBLIC
    CONAN_PKG::glm
    CONAN_PKG::gtest
)

target_include_directories(ModelTestLib
  PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/tests
)