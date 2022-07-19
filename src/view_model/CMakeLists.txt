add_library(ViewModelLib OBJECT
    Scene.h
)

target_link_libraries(ViewModelLib
  PUBLIC
    CONAN_PKG::glm
)

target_include_directories(ViewModelLib
  PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)