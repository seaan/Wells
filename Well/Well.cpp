//
// Created by sean on 2/4/19.
//
#include <cstring>
#include "Well.h"

Well::Well(char *id, char *company, int num_sensors) {
    this->_id = new char();
    this->_company = new char();
    strcpy(_id, id);
    strcpy(_company, company);
    this->_num_sensors = num_sensors;

    _enabled = false;
}

void Well::update() {
    for (Sensor *sensor: _sensors) {
        sensor->update();
    }
}

void Well::setEnabled(bool e) {
    this->_enabled = e;
}

bool Well::getEnabled() {
    return this->_enabled;
}

char *Well::getid() {
    return this->_id;
}

char *Well::getCompany() {
    return this->_company;
}

void
Well::addSensor(char *type, char *class_name, char *display_name, char *units, char *abbrev, double min, double max) {
    Sensor *sensor = new Sensor(type, class_name, display_name, units, abbrev, min, max);
    this->_sensors.push_back(sensor);
}

unsigned int Well::getNumSensors() {
    return this->_num_sensors;
}

std::vector<Sensor *> Well::getSensors() {
    return this->_sensors;
}