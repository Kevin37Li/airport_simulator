cmake_minimum_required(VERSION 3.15)
project(airport_simulator)

set(CMAKE_CXX_STANDARD 11)

add_executable(airport_simulator main.cpp Queue.cpp Queue.h boolSource.cpp boolSource.h averager.cpp averager.h runway.cpp runway.h)