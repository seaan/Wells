//
// Created by sean on 2/4/19.
//

#include "WellMsg.h"

WellMsg::WellMsg(Well *well) {
    this->_well = well;
    this->_well_info = new char();

    std::sprintf(_well_info, "%s: %s", this->_well->getCompany(), this->_well->getid());

    for (Sensor *sensor: this->_well->getSensors()) {
        if(sensor->getEnabled()) {
            char *info = new char();
            std::sprintf(info, "%s: %.2f %s", sensor->getDisplayName(), sensor->getValue(), sensor->getAbbrev());
            this->_sensor_info.push_back(info);
        }
    }
}

WellMsg::~WellMsg() {
    delete this->_well_info;
    this->_sensor_info.clear();
}

char *WellMsg::getWellInfo() {
    return _well_info;
}

std::vector<char *> WellMsg::getSensorInfo() {
    return _sensor_info;
}