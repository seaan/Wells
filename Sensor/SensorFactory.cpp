//
// Created by sean on 2/25/19.
//

#include "SensorFactory.h"

SensorFactory::~SensorFactory() {

}

SensorFactory *SensorFactory::getInstance() {
    static SensorFactory *instance = nullptr;
    if(instance == nullptr)
        instance = new SensorFactory();
    return instance;
}

void SensorFactory::defineType(SensorData *sensor_data) {
    std::string key(sensor_data->_type); // convert to string
    _types.insert({key, sensor_data});
}

Sensor *SensorFactory::createSensor(char *type) {
    return new Sensor(_types[type]);
}

SensorFactory::SensorFactory() {

}
