/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: DataGen.h
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#ifndef WELLS_DATAGEN_H
#define WELLS_DATAGEN_H

#include "../Sensor/Sensor.h"

class Sensor; // forward declaration TODO meh

class DataGen {
public:
    DataGen() {}

    ~DataGen() {}

    virtual double generate(double min, double max, double step, double value, Sensor *link);
};

#endif //WELLS_DATAGEN_H
