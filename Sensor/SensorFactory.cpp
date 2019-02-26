//
// Created by sean on 2/25/19.
//

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
