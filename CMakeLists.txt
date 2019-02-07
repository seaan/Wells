cmake_minimum_required(VERSION 3.13)
project(Wells)

set(CMAKE_CXX_STANDARD 11)

add_executable(Wells main.cpp Sensor/Sensor.cpp Sensor/Sensor.h Simulation/Simulation.cpp Simulation/Simulation.h Well/Well.cpp Well/Well.h Display/Display.cpp Display/Display.h Well/WellMsg.cpp Well/WellMsg.h Utility/OilFieldDataParser.h Utility/OilFieldDataParser.cpp)