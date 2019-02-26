//
// Created by sean on 2/25/19.
//

#ifndef WELLS_SENSORFACTORY_H
#define WELLS_SENSORFACTORY_H


#include "Sensor.h"
#include <map>

class SensorFactory {
public:
    ~SensorFactory();

    static SensorFactory *getInstance();

    void defineType(SensorConfig *config);

    Sensor *createSensor(char *type);

private:
    SensorFactory();

    std::map<std::string, SensorConfig *> _types;
};


#endif //WELLS_SENSORFACTORY_H
