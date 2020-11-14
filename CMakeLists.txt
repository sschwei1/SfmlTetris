# minimum version of CMake required
cmake_minimum_required(VERSION 3.16)

# project name
project(SfmlTetris)

# c++ verson
set(CMAKE_CXX_STANDARD 20)

set(SFML_INCLUDE_DIR "./SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "./SFML-2.5.1/build/lib")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(SfmlTetris main.cpp)
target_link_libraries(SfmlTetris sfml-graphics sfml-window sfml-system)