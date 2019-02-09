//
// Created by sean on 2/4/19.
//

#include "Simulation.h"
#include "../Well/WellMsg.h"
#include "../Utility/OilFieldDataParser.h"

#include <sys/types.h>
#include <sys/timeb.h>
#include <time.h>
#include <stdlib.h>

#include <ncurses.h> // <conio.h> windows
#include <cstring>

void Simulation::run() {
    struct timeb struct_time;
    double current_time;
    double target_time;
    bool done = false;  // while loop flag

    srand((unsigned int) (time(NULL))); // seed srand
    readFile("../OilFieldData.xml");

    ftime(&struct_time);    // Get start struct_time
    current_time = struct_time.time + (((double) (struct_time.millitm)) / 1000.0); // Convert to double
    target_time = current_time + 5.0; // Set next 5 second interval struct_time

    while (!done)     // Start an eternal loop
    {
        ftime(&struct_time);    // Get the current struct_time
        current_time = struct_time.time + (((double) (struct_time.millitm)) / 1000.0); // Convert to double
        // Check for 5 second interval to print status to screen
        if (current_time >= target_time) {
            target_time += 5.0; // Set struct_time for next 5 second interval
            update();
            log();
            cout << "- - - - - - - - - - - - - - - - - -\n";
        }
    }

    cout << "Done";
}

void Simulation::update() {
    for (Well *well: _wells) {
        well->update();
    }
}

void Simulation::log() {
    for (Well *well: this->_wells) {
        if (well->getEnabled()) {
            WellMsg *msg = new WellMsg(well);
            this->_display->log(msg);
            delete msg;
        }
    }
}

void Simulation::readFile(const char *fileName) {
    OilFieldDataParser data = OilFieldDataParser("../OilFieldData.xml");

    for (int i = 0; i < data.getWellCount(); i++) {
        char *id = new char();
        char *opr = new char();
        int num_sensors;
        data.getWellData(id, opr, &num_sensors);
        Well *well = new Well(id, opr, num_sensors);
        _wells.push_back(well);
    }

    for (Well *well: _wells) {
        char *type = new char();
        char *class_name = new char();
        char *display_name = new char();
        char *units = new char();
        char *abbrev = new char();
        double min, max;

        for (int i = 0; i < well->getNumSensors(); i++) {
            data.getSensorData(well->getid(), type, class_name, display_name, &min, &max, units, abbrev);

            well->addSensor(type, class_name, display_name, units, abbrev, min, max);
        }
    }
}

bool Simulation::setEnabledWell(char *well_id, bool e) {
    for(Well *well: _wells) {
        if(strcmp(well->getid(), well_id) == 0) {
            well->setEnabled(e);
            return true; // id is unique for the wells
        }
    }
    return false;
}

bool Simulation::setEnabledSensor(char *well_id, char *sensor_type, bool e) {
    for(Well *well: _wells) {
        if(strcmp(well->getid(), well_id) == 0) {
            return well->setEnabledSensor(sensor_type, e);
        }
    }
    return false;
}
