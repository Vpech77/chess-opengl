cmake_minimum_required(VERSION 3.5)

project(chessProj LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)
include_directories(src/interface_graphique src/chess_game)

add_subdirectory(src/interface_graphique)
add_subdirectory(src/chess_game)

add_executable(chessProj src/main.cpp)

target_link_libraries(chessProj glfw GLEW libGLEW.so libGLU.so libGL.so interface_graphique chess_game)