/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: SensorConfig.h
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

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
