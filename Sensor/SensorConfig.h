//
// Created by seanw on 2/25/2019.
//

#ifndef WELLS_SENSORCONFIG_H
#define WELLS_SENSORCONFIG_H


#include "../DataGen/DataGen.h"

class DataGen; // forward declaration TODO meh

struct SensorConfig {
    char *_type, *_class_name, *_display_name, *_units, *_abbrev, *_link_info;
    double _min, _max, _step, _init_value;
    DataGen *_gen;

    SensorConfig(char *type, char *class_name, char *display_name, char *units, char *abbrev, char *gen_alg,
                 char *link_info, double min, double max, double step, bool min_undef, bool max_undef);
};


#endif //WELLS_SENSORCONFIG_H
