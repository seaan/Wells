/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: WellFactory.h
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#ifndef WELLS_WELLFACTORY_H
#define WELLS_WELLFACTORY_H

#include "Well.h"
#include "../Utility/OilFieldDataParser.h"
#include "../Sensor/SensorFactory.h"

class WellFactory {
public:
    ~WellFactory();

    static WellFactory *getInstance();

    Well *createWell(OilFieldDataParser *data);

private:
    WellFactory();

    SensorFactory *_sensor_factory;
};


#endif //WELLS_WELLFACTORY_H
