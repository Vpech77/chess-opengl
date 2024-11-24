cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

set(PIECES3D_SOURCES pieces3D/piece3D.cpp
                     pieces3D/pawn3D.cpp)

set(PIECES3D_HEADERS pieces3D/header3D.h
                     pieces3D/piece3D.h 
                     pieces3D/pawn3D.h )

add_library(chess_game STATIC ${PIECES3D_SOURCES} ${PIECES3D_HEADERS}
                              plato.h plato.cpp
                              )