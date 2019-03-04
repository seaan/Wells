/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Sensor.h
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#ifndef WELLS_SENSOR_H
#define WELLS_SENSOR_H

#include <cstring>
#include "DataGen.h"
#include "SensorConfig.h"

class Sensor {
public:
    Sensor(SensorConfig *sensor_data);

    ~Sensor();

    void update();

    void setEnabled(bool e);

    bool getEnabled();

    char *getDisplayName();

    char *getAbbrev();

    char *getType();

    double getValue();

private:
    SensorConfig *_sensor_data;

    double _value;
    bool _enabled;
};


#endif //WELLS_SENSOR_H
