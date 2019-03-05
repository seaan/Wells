/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: SensorFactory.cpp
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "SensorFactory.h"

SensorFactory::~SensorFactory() {

}

SensorFactory *SensorFactory::getInstance() {
    static SensorFactory *instance = nullptr;
    if (instance == nullptr)
        instance = new SensorFactory();
    return instance;
}

void SensorFactory::defineType(SensorConfig *config) {
    std::string key(config->_type); // convert to string
    _types.insert({key, config});
}

Sensor *SensorFactory::createSensor(char *type) {
    return new Sensor(_types[type]);
}

SensorFactory::SensorFactory() {

}
