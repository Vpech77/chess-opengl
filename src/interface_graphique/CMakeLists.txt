cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

add_library(interface_graphique STATIC renderer.h renderer.cpp 
                             vertexarray.h vertexarray.cpp 
                             vertexbuffer.h vertexbuffer.cpp 
                             shader.h shader.cpp
                             stb_image.h stb_image.cpp
                             uvbuffer.h uvbuffer.cpp 
                             texture.h texture.cpp 
                             object.h object.cpp
                             camera.h camera.cpp
                             controls.h controls.cpp
                             fpscontrols.h fpscontrols.cpp
                             navigationcontrols.h navigationcontrols.cpp)