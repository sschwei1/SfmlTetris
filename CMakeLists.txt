# minimum version of CMake required
cmake_minimum_required(VERSION 3.15)

#define constants
set(PROJECT_NAME SfmlTetris)
set(SOURCE_FILE source/main.cpp source/Game.cpp source/Game.h source/states/State.cpp source/states/State.h source/states/GameState.cpp source/states/GameState.h source/entities/Entity.cpp source/entities/Entity.h source/states/MainMenuState.cpp source/states/MainMenuState.h source/resources/Button.cpp source/resources/Button.h)

# project name
project(${PROJECT_NAME})

# c++ version
set(CMAKE_CXX_STANDARD 20)

# set libaries for linux
if (UNIX)
    set(SFML_INCLUDE_DIR "./SFML-2.5.1/include")
    set(SFML_LIBRARY_DIR "./SFML-2.5.1/build/lib")

    link_directories(SFML_LIBRARY_DIR)
    include_directories(SFML_INCLUDE_DIR)
endif (UNIX)

# set libaries for windows
if (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
endif (WIN32)

if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++)
endif()

find_package(SFML 2.5.1 COMPONENTS system window graphics audio network)
add_executable(${PROJECT_NAME} ${SOURCE_FILE})

set(SFML_STATIC_LIBRARIES TRUE)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

# copy config folder to output
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/source/config/ $<TARGET_FILE_DIR:${PROJECT_NAME}>/config/)

#copy fonts folder to output
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/source/fonts/ $<TARGET_FILE_DIR:${PROJECT_NAME}>/fonts/)