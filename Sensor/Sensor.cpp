//
// Created by sean on 2/4/19.
//

#include <cstring>
#include <stdlib.h>

#include "Sensor.h"

/**
 *
 * @param type
 * @param class_name
 * @param display_name
 * @param units
 * @param abbrev
 * @param gen_alg
 * @param link
 * @param min
 * @param max
 * @param step
 * @param min_undef
 * @param max_undef
 */
SensorData::SensorData(char *type, char *class_name, char *display_name, char *units, char *abbrev, char *gen_alg,
                       char *link, double min, double max, double step, bool min_undef, bool max_undef) {
    this->_type = new char();
    this->_class_name = new char();
    this->_display_name = new char();
    this->_units = new char();
    this->_abbrev = new char();
    this->_link = new char();// allocate space for all of our strings

    strcpy(this->_type, type);
    strcpy(this->_class_name, class_name);
    strcpy(this->_display_name, display_name);
    strcpy(this->_units, units);
    strcpy(this->_abbrev, abbrev); // copy the input into the member variables

    this->_min = min;
    this->_max = max;
    this->_step = step;
    this->_min_undef = min_undef;
    this->_max_undef = max_undef;
    this->_link = link;

    if (strcmp(gen_alg, "RAND_MIN2MAX") == 0) {
        _gen = new RandGen();
    }
    if (strcmp(gen_alg, "STEPINC_MIN2MAX") == 0) {
        _gen = new StepIncGen(min);
    }
    if (strcmp(gen_alg, "STEPDEC_MAX2MIN") == 0) {
        _gen = new StepDecGen(max);
    }
    if (strcmp(gen_alg, "FOLLOWLINK_IFGREATER") == 0) {
        _gen = new FollowGreaterGen();
    }
    if (strcmp(gen_alg, "FOLLOWLINK_IFCHANGED") == 0) {
        _gen = new FollowChangedGen();
    }
}

/**
 * Constructs Sensor object, ises arguments to set member variables.
 * @param
 */
Sensor::Sensor(SensorData *sensor_data) {
    this->_sensor_data = sensor_data;

    this->_value = 0; // starts out as 0, will be updated in update()
    this->_enabled = true; // starts out false, user will enable
}

/**
 * Destructor for sensor.
 */
Sensor::~Sensor() {
    delete _sensor_data;
}

/**
 * Generates a random number for _value and sets it.
 */
void Sensor::update() {
    this->_value = this->_sensor_data->_gen->generate(_sensor_data->_min, _sensor_data->_max, _sensor_data->_step);
}

/**
 * Sets enabled or disabled status for sensor status monitoring.
 * @param e new enabled state for the sensor
 */
void Sensor::setEnabled(bool e) {
    this->_enabled = e;
}

/**
 * Accessor for enabled or disabled status for sensor status monitoring.
 * @return boolean indicating enabled status
 */
bool Sensor::getEnabled() {
    return this->_enabled;
}

/**
 * Accessor for display name of sensor.
 * @return sensor display name
 */
char *Sensor::getDisplayName() {
    return this->_sensor_data->_display_name;
}

/**
 * Accessor for sensor unit abbreviation.
 * @return sensor unit abbreviation
 */
char *Sensor::getAbbrev() {
    return this->_sensor_data->_abbrev;
}

/**
 * Acccessor for sensor type.
 * @return sensor type
 */
char *Sensor::getType() {
    return this->_sensor_data->_type;
}

/**
 * Accessor for sensor value.
 * @return sensor value
 */
double Sensor::getValue() {
    return this->_value;
}
