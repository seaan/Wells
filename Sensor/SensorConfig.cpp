//
// Created by seanw on 2/25/2019.
//

#include "SensorConfig.h"

/**
 *
 * @param type
 * @param class_name
 * @param display_name
 * @param units
 * @param abbrev
 * @param gen_alg
 * @param link_info
 * @param min
 * @param max
 * @param step
 * @param min_undef
 * @param max_undef
 */
SensorConfig::SensorConfig(char *type, char *class_name, char *display_name, char *units, char *abbrev, char *gen_alg,
                           char *link_info, double min, double max, double step, bool min_undef, bool max_undef) {
    this->_type = new char[32];
    this->_class_name = new char[32];
    this->_display_name = new char[32];
    this->_units = new char[32];
    this->_abbrev = new char[32];
    this->_link_info = new char[32];// allocate space for all of our strings

    strcpy(this->_type, type);
    strcpy(this->_class_name, class_name);
    strcpy(this->_display_name, display_name);
    strcpy(this->_units, units);
    strcpy(this->_abbrev, abbrev);
    strcpy(this->_link_info, link_info); // copy the input into the member variables

    this->_min = min;
    this->_max = max;
    this->_step = step;
    this->_min_undef = min_undef;
    this->_max_undef = max_undef;

    this->_init_value = 0;
    if (strcmp(gen_alg, "RAND_MIN2MAX") == 0) {
        this->_gen = new RandGen();
    }
    if (strcmp(gen_alg, "STEPINC_MIN2MAX") == 0) {
        this->_gen = new StepIncGen();
        this->_init_value = max;
    }
    if (strcmp(gen_alg, "STEPDEC_MAX2MIN") == 0) {
        this->_gen = new StepDecGen();
        this->_init_value = min;
    }
    if (strcmp(gen_alg, "FOLLOWLINK_IFGREATER") == 0) {
        this->_gen = new FollowGreaterGen();
    }
    if (strcmp(gen_alg, "FOLLOWLINK_IFCHANGED") == 0) {
        this->_gen = new FollowChangedGen();
    }
}