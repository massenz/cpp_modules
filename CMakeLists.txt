cmake_minimum_required(VERSION 3.30)
project(cpp_modules)

set(CMAKE_CXX_STANDARD 20)
# Ensure that we are not using GNU extensions
# so that the module can be linked using clang++
set(CMAKE_CXX_EXTENSIONS OFF)
# Set output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)

add_executable(use_demo src/main.cpp)
target_sources(use_demo
        PRIVATE
        FILE_SET cxx_modules TYPE CXX_MODULES FILES src/demo.cppm
)
