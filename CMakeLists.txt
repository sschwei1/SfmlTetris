# minimum version of CMake required
cmake_minimum_required(VERSION 3.15)

#define constants
set(PROJECT_NAME SfmlTetris)
set(SOURCE_FILE main.cpp)

# project name
project(${PROJECT_NAME})

# c++ verson
set(CMAKE_CXX_STANDARD 20)

if (UNIX)
    set(SFML_INCLUDE_DIR "./SFML-2.5.1/include")
    set(SFML_LIBRARY_DIR "./SFML-2.5.1/build/lib")

    link_directories(SFML_LIBRARY_DIR)
    include_directories(SFML_INCLUDE_DIR)
endif (UNIX)

if (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
endif (WIN32)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
add_executable(${PROJECT_NAME} ${SOURCE_FILE})

set(SFML_STATIC_LIBRARIES TRUE)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
