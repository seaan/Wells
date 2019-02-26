//
// Created by sean on 2/4/19.
//

#ifndef WELLS_SENSOR_H
#define WELLS_SENSOR_H

#include <cstring>
#include "SensorConfig.h"

class SensorConfig; // forward declaration TODO meh

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

    char *getLinkInfo();

    void setLink(Sensor *link);

    bool valueChanged();

private:
    SensorConfig *config;

    Sensor *_link;
    double _value, _last_value;
    bool _enabled;
};


#endif //WELLS_SENSOR_H
