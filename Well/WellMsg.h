/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: WellMsg.h
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#ifndef WELLS_WELLMSG_H
#define WELLS_WELLMSG_H

#include "Well.h"
#include <string>
#include <vector>

class WellMsg {
public:
    WellMsg(Well *well);

    ~WellMsg();

    std::vector<char *> getSensorInfo();

    char *getWellInfo();

private:
    char *_well_info;
    std::vector<char *> _sensor_info;
};


#endif //WELLS_WELLMSG_H
