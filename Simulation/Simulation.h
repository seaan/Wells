/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Simulation.h
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#ifndef WELLS_SIMULATION_H
#define WELLS_SIMULATION_H

#include "../Well/Well.h"
#include "../Display/Display.h"
#include "../Utility/OilFieldDataParser.h"
#include "../Sensor/SensorFactory.h"
#include "../Well/WellFactory.h"

class Simulation {
public:
    Simulation();

    void run();

private:
    void update();

    void log();

    void readFile(const char *file_name);

    void editWell();

    void editSensor();

    std::vector<Well *> _wells;
    Display *_display;
    OilFieldDataParser *_data;

    WellFactory *_well_factory;
};


#endif //WELLS_SIMULATION_H
