//
// Created by sean on 2/4/19.
//

#ifndef WELLS_SENSOR_H
#define WELLS_SENSOR_H

#include <cstring>
#include "DataGen.h"

struct SensorData {
    char *_type, *_class_name, *_display_name, *_units, *_abbrev, *_link;
    double _min, _max, _step;
    bool _min_undef, _max_undef;
    DataGen *_gen;

    SensorData(char *type, char *class_name, char *display_name, char *units, char *abbrev, char *gen_alg, char *link,
               double min, double max, double step, bool min_undef, bool max_undef);
};

class Sensor {
public:
    Sensor(SensorData *sensor_data);

    ~Sensor();

    void update();

    void setEnabled(bool e);

    bool getEnabled();

    char *getDisplayName();

    char *getAbbrev();

    char *getType();

    double getValue();

private:
    SensorData *_sensor_data;

    double _value;
    bool _enabled;
};


#endif //WELLS_SENSOR_H
