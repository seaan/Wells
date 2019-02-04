//
// Created by sean on 2/4/19.
//

#ifndef WELLS_WELL_H
#define WELLS_WELL_H

#include "../Sensor/Sensor.h"
#include <string>
#include <vector>

class Well {
public:
    void update();
private:
    std::vector<Sensor> _sensors;

    unsigned int _id;
    std::string _company;
};


#endif //WELLS_WELL_H
