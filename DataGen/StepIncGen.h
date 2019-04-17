//
// Created by sean on 4/10/19.
//

#ifndef WELLS_STEPINCGEN_H
#define WELLS_STEPINCGEN_H

#include "../Sensor/Sensor.h"

class StepIncGen : public DataGen {
public:
    double generate(double min, double max, double step, double value, Sensor *link);
};


#endif //WELLS_STEPINCGEN_H
