//
// Created by sean on 2/4/19.
//

#include <cstring>
#include "Sensor.h"

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
}

Sensor::~Sensor() {
    delete _type;
    delete _class_name;
    delete _display_name;
    delete _units;
    delete _abbrev;
}

void Sensor::update() {

}

char *Sensor::getDisplayName() {
    return this->_display_name;
}

char *Sensor::getAbbrev() {
    return this->_abbrev;
}

double Sensor::getValue() {
    return this->_value;
}