add_library(ModelLib OBJECT
    Icon.cpp
    Ladder.cpp
    Player.cpp
    Renderable.cpp
    Wall.cpp
)

target_link_libraries(ModelLib
  PUBLIC
    CONAN_PKG::glm
)

target_include_directories(ModelLib
  PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)