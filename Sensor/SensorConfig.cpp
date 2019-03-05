/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: SensorConfig.cpp
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include <cfloat>
#include "SensorConfig.h"
#include "../DataGen/DataGenFactory.h"

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

    if (max_undef) max = DBL_MAX;
    if (min_undef) min = DBL_MIN;

    this->_step = step;

    this->_init_value = 0;

    DataGenFactory *datagen_factory = DataGenFactory::getInstance();
    this->_gen = datagen_factory->createDataGen(gen_alg, &this->_init_value, max, min);
}