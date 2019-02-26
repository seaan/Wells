cmake_minimum_required(VERSION 3.10)
project(Wells)

set(CMAKE_CXX_STANDARD 11)

add_executable(Wells main.cpp Sensor/Sensor.cpp Sensor/Sensor.h Simulation/Simulation.cpp Simulation/Simulation.h Well/Well.cpp Well/Well.h Display/Display.cpp Display/Display.h Well/WellMsg.cpp Well/WellMsg.h Utility/OilFieldDataParser.h Utility/OilFieldDataParser.cpp Sensor/SensorFactory.cpp Sensor/SensorFactory.h Well/WellFactory.cpp Well/WellFactory.h DataGen/DataGen.cpp DataGen/DataGen.h Sensor/SensorConfig.cpp Sensor/SensorConfig.h DataGen/DataGenFactory.cpp DataGen/DataGenFactory.h)