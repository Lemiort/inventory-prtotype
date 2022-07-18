# dear-imgui-conan-example

Just a simple example on how to integrate imgui on your own application using conan to manage dependencies

## How to Use

1. Install conan: https://docs.conan.io/en/latest/installation.html
2. Clone this repo: `git clone https://github.com:Lemiort/dear-imgui-conan-example.git`
3. Install dependencies, compile and run

## Windows with Visual Studio

```bash
cd dear-imgui-conan-example
mkdir build
cd build
conan install .. --build=missing
cmake .. -G "Visual Studio 17 2022" -A x64
cmake --build .
cd bin
dear-imgui-conan
```

## Linux

```bash
cd dear-imgui-conan-example
mkdir build
cd build
conan install .. --build=missing
cmake ..
cmake --build .
cd bin
dear-imgui-conan
```
