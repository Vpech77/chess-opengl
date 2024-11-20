cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

add_library(chess_game STATIC plato.h plato.cpp
                              loadModel.h loadModel.cpp)