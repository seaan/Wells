//
// Created by sean on 2/4/19.
//

#include <cstring>
#include <stdlib.h>

#include "Sensor.h"

/**
 * Constructs Sensor object, ises arguments to set member variables.
 * @param type sensor type
 * @param class_name sensor class name
 * @param display_name sensor display name
 * @param units sensor units
 * @param abbrev sensor unit abbreviation
 * @param min maximum sensor value
 * @param max minimum sensor value
 */
Sensor::Sensor(SensorData *sensor_data) {
    this->_sensor_data = sensor_data;

    this->_value = 0; // starts out as 0, will be updated in update()
    this->_enabled = false; // starts out false, user will enable
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
    this->_value = this->_sensor_data->_min + (rand() % (int) (this->_sensor_data->_max - this->_sensor_data->_min));
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