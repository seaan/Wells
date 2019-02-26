//
// Created by sean on 2/25/19.
//

#ifndef WELLS_DATAGEN_H
#define WELLS_DATAGEN_H

#include "Sensor.h"

class Sensor; // forward declaration TODO meh

class DataGen {
public:
    DataGen() {}

    ~DataGen() {}

    virtual double generate(double min, double max, double step, double value, Sensor *link);
};

class RandGen : public DataGen {
public:
    double generate(double min, double max, double step, double value, Sensor *link);
};

class StepIncGen : public DataGen {
public:
    double generate(double min, double max, double step, double value, Sensor *link);
};

class StepDecGen : public DataGen {
public:
    double generate(double min, double max, double step, double value, Sensor *link);
};

class FollowGreaterGen : public DataGen {
public:
    double generate(double min, double max, double step, double value, Sensor *link);
};

class FollowChangedGen : public DataGen {
public:
    double generate(double min, double max, double step, double value, Sensor *link);
};

#endif //WELLS_DATAGEN_H
