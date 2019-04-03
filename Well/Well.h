/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Well.h
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#ifndef WELLS_WELL_H
#define WELLS_WELL_H

#include "../Sensor/Sensor.h"
#include "../Utility/OilFieldDataParser.h"
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

    std::vector<char *> getSensorTypes();

    void initLinks();

	void drawCheckboxes(CDC *cdc, int ULX, int ULY, int LRX, int LRY);

	void drawSensors(CDC *cdc, int ULX, int ULY, int LRX, int LRY);

protected:
    std::vector<Sensor *> _sensors;

    bool _enabled;

    char *_id;
    char *_company;
    int _num_sensors;
};


#endif //WELLS_WELL_H
