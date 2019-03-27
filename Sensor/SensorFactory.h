/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: SensorFactory.h
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#ifndef WELLS_SENSORFACTORY_H
#define WELLS_SENSORFACTORY_H


#include "Sensor.h"
#include <map>
#include <string>

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
