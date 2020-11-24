# minimum version of CMake required
cmake_minimum_required(VERSION 3.15)

#define constants
set(PROJECT_NAME SfmlTetris)
set(SOURCE_FILE "source/main.cpp" "source/Game.cpp" "source/Game.h" source/states/State.cpp source/states/State.h source/states/GameState.cpp source/states/GameState.h source/entities/Entity.cpp source/entities/Entity.h)

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

find_package(SFML 2.5.1 COMPONENTS system window graphics audio network)
add_executable(${PROJECT_NAME} ${SOURCE_FILE})

set(SFML_STATIC_LIBRARIES TRUE)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
