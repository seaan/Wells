//
// Created by sean on 2/4/19.
//

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
