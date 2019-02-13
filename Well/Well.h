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

    void setEnabled(bool e);

    bool setEnabledSensor(char *type, bool e);

    bool getEnabled();

    char *getid();

    char *getCompany();

    int getNumSensors();

    std::vector<Sensor *> getSensors();

    void addSensor(Sensor *sensor);

    std::vector<char *> findSensorTypes();

protected:
    std::vector<Sensor *> _sensors;

    bool _enabled;

    char *_id;
    char *_company;
    int _num_sensors;
};


#endif //WELLS_WELL_H
