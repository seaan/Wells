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
Sensor::Sensor(char *type, char *class_name, char *display_name, char *units, char *abbrev, double min, double max) {
    this->_type = new char();
    this->_class_name = new char();
    this->_display_name = new char();
    this->_units = new char();
    this->_abbrev = new char();

    strcpy(this->_type, type);
    strcpy(this->_class_name, class_name);
    strcpy(this->_display_name, display_name);
    strcpy(this->_units, units);
    strcpy(this->_abbrev, abbrev);
    this->_min = min;
    this->_max = max;
    this->_value = 0;
    this->_enabled = false;

    if (this->_max == 0) this->_max = 10000;
}

/**
 * Destructor for sensor.
 */
Sensor::~Sensor() {
    delete _type;
    delete _class_name;
    delete _display_name;
    delete _units;
    delete _abbrev;
}

/**
 * Generates a random number for _value and sets it.
 */
void Sensor::update() {
    _value = _min + (rand() % (int) (_max - _min));
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
    return this->_display_name;
}

/**
 * Accessor for sensor unit abbreviation.
 * @return sensor unit abbreviation
 */
char *Sensor::getAbbrev() {
    return this->_abbrev;
}

/**
 * Acccessor for sensor type.
 * @return sensor type
 */
char *Sensor::getType() {
    return this->_type;
}

/**
 * Accessor for sensor value.
 * @return sensor value
 */
double Sensor::getValue() {
    return this->_value;
}