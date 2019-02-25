//
// Created by sean on 2/25/19.
//

#include "SensorFactory.h"

SensorFactory::~SensorFactory() {

}

SensorFactory *SensorFactory::getInstance() {
    static SensorFactory *instance = NULL;
    if(instance == NULL)
        instance = new SensorFactory();
    return instance;
}

void SensorFactory::defineType(SensorData sensor_data) {
    types.insert({sensor_data._type, sensor_data});
}

Sensor *SensorFactory::createSensor(char *type) {
    return new Sensor(types[type]);
}

SensorFactory::SensorFactory() {

}
