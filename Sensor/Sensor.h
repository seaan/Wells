//
// Created by sean on 2/4/19.
//

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
