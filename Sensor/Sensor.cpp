//
// Created by sean on 2/4/19.
//

#include "Sensor.h"

/**
 * Constructs Sensor object, ises arguments to set member variables.
 * @param
 */
Sensor::Sensor(SensorConfig *sensor_data) {
    this->config = sensor_data;

    this->_value = this->config->_init_value;
    this->_last_value = this->config->_init_value;
    this->_enabled = true; // starts out true, user will enable/disable
}

/**
 * Destructor for sensor.
 */
Sensor::~Sensor() {
    delete config;
}

/**
 * Generates a random number for _value and sets it.
 */
void Sensor::update() {
    this->_last_value = _value;
    this->_value = this->config->_gen->generate(config->_min, config->_max, config->_step, 0, _link);
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
    return this->config->_display_name;
}

/**
 * Accessor for sensor unit abbreviation.
 * @return sensor unit abbreviation
 */
char *Sensor::getAbbrev() {
    return this->config->_abbrev;
}

/**
 * Acccessor for sensor type.
 * @return sensor type
 */
char *Sensor::getType() {
    return this->config->_type;
}

/**
 * Accessor for sensor value.
 * @return sensor value
 */
double Sensor::getValue() {
    return this->_value;
}

/**
 *
 * @return
 */
char *Sensor::getLinkInfo() {
    return this->config->_link_info;
}

/**
 *
 * @param link
 */
void Sensor::setLink(Sensor *link) {
    this->_link = link;
}

/**
 *
 * @return
 */
bool Sensor::valueChanged() {
    return this->_last_value != this->_value;
}
