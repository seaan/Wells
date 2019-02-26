//
// Created by sean on 2/4/19.
//
#include <cstring>
#include "Well.h"

/**
 * Constructs a Well object, sets well ID, company, and number of sensors.
 * @param the well's ID
 * @param company the well's company
 * @param num_sensors the number of sensors the well contains
 */
Well::Well(char *id, char *company, int num_sensors) {
    this->_id = new char();
    this->_company = new char();

    strcpy(_id, id);
    strcpy(_company, company);
    this->_num_sensors = num_sensors;

    _enabled = true;
}

/**
 * Iterates through each sensor in _sensors to call their update function.
 */
void Well::update() {
    for (Sensor *sensor: _sensors) {
        sensor->update();
    }
}

/**
 * Sets enabled or disabled status for status monitoring.
 * @param e new enabled state for the well.
 */
void Well::setEnabled(bool e) {
    this->_enabled = e;
}

/**
 * Finds sensor of specified type and enables or disables it.
 * @param type the sensor type to access
 * @param e new enabled state for the sensor
 * @return Indicates success of search.
 */
bool Well::setEnabledSensor(char *type, bool e) {
    for (Sensor *sensor: _sensors) {
        if (strcmp(sensor->getType(), type) == 0) {
            sensor->setEnabled(e);
            return true;
        }
    }
    return false;
}

/**
 * Accessor for enabled status.
 * @return boolean indicating if well is enabled
 */
bool Well::getEnabled() {
    return this->_enabled;
}

/**
 * Accessor for well ID.
 * @return well ID
 */
char *Well::getid() {
    return this->_id;
}

/**
 * Accessor for well company.
 * @return well company name
 */
char *Well::getCompany() {
    return this->_company;
}

/**
 * Adds the given Sensor object to _sensors.
 * @param sensor Sensor object to add
 */
void Well::addSensor(Sensor *sensor) {
    this->_sensors.push_back(sensor);
}

/**
 * Accessor for number of sensors.
 * @return number of sensors the well contains
 */
int Well::getNumSensors() {
    return this->_num_sensors;
}

/**
 * Accessor for sensors collection.
 * @return vector of Sensor objects contained by the well
 */
std::vector<Sensor *> Well::getSensors() {
    return this->_sensors;
}

/**
 * Finds all the types of sensors in this well.
 * @return vector of sensor types found in the well
 */
std::vector<char *> Well::getSensorTypes() {
    std::vector<char *> result;
    for (Sensor *sensor: _sensors) {
        result.push_back(sensor->getType());
    }
    return result;
}