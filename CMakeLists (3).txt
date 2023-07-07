cmake_minimum_required(VERSION 3.23)
project(program5)

set(CMAKE_CXX_STANDARD 14)

add_executable(program5 main.cpp FlightPlanner.cpp FlightPlanner.h Flight.cpp Flight.h Destination.cpp Destination.h)
