cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

add_library(chess_game STATIC piece.h  piece.cpp
                              pawn.h   pawn.cpp
                              rook.h   rook.cpp
                              bishop.h bishop.cpp
                              knight.h knight.cpp
                              king.h   king.cpp
                              queen.h  queen.cpp
                              headerPieces.h
                              plato.h plato.cpp
                              game.h game.cpp)