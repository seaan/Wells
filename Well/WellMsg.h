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
    WellMsg(Well* well);

    std::vector<std::string> sensorInfo();
    unsigned int id;
    std::string company;
private:
    Well *_well;
};


#endif //WELLS_WELLMSG_H
