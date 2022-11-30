cmake_minimum_required(VERSION 3.23)
project(AirlineRoutes)

set(CMAKE_CXX_STANDARD 14)

add_executable(AirlineRoutes main.cpp FindAirport.cpp FindAirport.h AirlineManager.cpp AirlineManager.h RouteFinder.cpp RouteFinder.h HelperFunctions.cpp HelperFunctions.h ReadWrite.cpp ReadWrite.h)
