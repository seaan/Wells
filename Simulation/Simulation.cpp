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
#include <sys/select.h>
#include <unistd.h>
#include <cstring>

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

    while(!done)     // Start an eternal loop
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
    _data = new OilFieldDataParser("../OilFieldData.xml");

    for(int i = 0; i < _data->getWellCount(); i++) {
        char *id = new char();
        char *opr = new char();
        int num_sensors;
        _data->getWellData(id, opr, &num_sensors);
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

        for(int i = 0; i < well->getNumSensors(); i++) {
            _data->getSensorData(well->getid(), type, class_name, display_name, &min, &max, units, abbrev);

            well->addSensor(type, class_name, display_name, units, abbrev, min, max);
        }
    }
}

void Simulation::editWell() {
    char* addrem = new char();
    char* id = new char();
    bool enabled = false;

    cout << "Well ID list: \n";
    _data->printWellData();

    cout << "\nWould you like to add or remove a well from the display? [add/remove]:";
    cin >> addrem;
    cout << "Please enter the well ID: ";
    cin >> id;

    if(strcmp(addrem, "add") == 0) {
        enabled = true;
    }
    else if(strcmp(addrem, "remove") == 0){
        enabled = false;
    }
    else {
        cout << "Error reading input, please try again.\n";
        return;
    }

    for(Well *well: _wells) {
        if(strcmp(well->getid(), id) == 0) {
            well->setEnabled(enabled);
        }
    }
}

void Simulation::editSensor() {
    char* addrem = new char();
    char* id = new char();
    char *type = new char();
    bool enabled = false;

    cout << "\nWould you like to add or remove a sensor from the display? [add/remove]:";
    cin >> addrem;
    cout << "Please enter the well ID: ";
    cin >> id;

    if(strcmp(addrem, "add") == 0) {
        enabled = true;
    }
    else if(strcmp(addrem, "remove") == 0){
        enabled = false;
    }
    else {
        cout << "Error reading input, please try again.\n";
        return;
    }

    for(Well *well: _wells) {
        if(strcmp(well->getid(), id) == 0) {
            well->setEnabledSensor(type, enabled);
        }
    }
}