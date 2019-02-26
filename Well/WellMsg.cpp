//
// Created by sean on 2/4/19.
//

#include "WellMsg.h"

/**
 * Constructs WellMsg object, uses input well to create _well_info
 * and loops through well sensors to create _sensor_info strings.
 * @param well Well object to initialize member variables with
 */
WellMsg::WellMsg(Well *well) {
    this->_well_info = new char[64];

    std::sprintf(_well_info, "%s: %s", well->getCompany(), well->getid());

    for (Sensor *sensor: well->getSensors()) {
        if (sensor->getEnabled()) {
            char *info = new char[32];
            std::sprintf(info, "%s: %.2f %s", sensor->getDisplayName(), sensor->getValue(), sensor->getAbbrev());
            this->_sensor_info.push_back(info);
        }
    }
}

/**
 * Destructor for WellMsg.
 */
WellMsg::~WellMsg() {
    delete this->_well_info;
    this->_sensor_info.clear();
}

/**
 * Accessor for _well_info.
 * @return well info string
 */
char *WellMsg::getWellInfo() {
    return _well_info;
}

/**
 * Accessor for _sensor_info.
 * @return vector of strings with sensor info for the well
 */
std::vector<char *> WellMsg::getSensorInfo() {
    return _sensor_info;
}