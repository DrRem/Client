cmake_minimum_required(VERSION 3.14)
project(Socket)

set(CMAKE_CXX_STANDARD 17)

link_libraries(ws2_32)

add_executable(Socket main.cpp Socks.cpp Socks.h)

