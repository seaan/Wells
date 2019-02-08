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
    Well(char *id, char *company, int num_sensors);

    void update();

    char *getid();

    char *getCompany();

    unsigned int getNumSensors();

    std::vector<Sensor *> getSensors();

    void addSensor(char *type, char *class_name, char *display_name, char *units, char *abbrev, double min, double max);

protected:
    std::vector<Sensor *> _sensors;

    char *_id;
    char *_company;
    int _num_sensors;
};


#endif //WELLS_WELL_H
