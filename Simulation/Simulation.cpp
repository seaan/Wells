//
// Created by sean on 2/4/19.
//

#include "Simulation.h"

#include <sys/timeb.h>
#include <cstring>

/**
 * Constructs a Simulation object, initializes _display.
 */
Simulation::Simulation() {
    _display = new Display(&cout);
}

/**
 * Initializes and runs simulation, occurs until program completion.
 */
void Simulation::run() {
    struct timeb struct_time;
    double current_time;
    double target_time;
    bool done = false;  // while loop flag

    _well_factory = WellFactory::getInstance();

    srand((unsigned int) (time(NULL))); // seed srand
    readFile("../OilFieldData.xml");

    ftime(&struct_time);    // Get start struct_time
    current_time = struct_time.time + (((double) (struct_time.millitm)) / 1000.0); // Convert to double
    target_time = current_time + 5.0; // Set next 5 second interval struct_time

    while (!done)     // Start an eternal loop
    {
        // check for user input TODO re-enable
//        char input;
//        input = getchar();
//        if (input == 'w')
//            editWell(); // 'w' triggers well list editing
//        if (input == 's')
//            editSensor(); // 's' triggers sensor list editing

        ftime(&struct_time);    // Get the current struct_time
        current_time = struct_time.time + (((double) (struct_time.millitm)) / 1000.0); // Convert to double
        // Check for 5 second interval to print status to screen
        if (current_time >= target_time) {
            target_time += 1.0; // Set struct_time for next 5 second interval TODO change to 5
            update(); // update all wells before log
            log(); // log all wells status
            cout << "- - - - - - - - - - - - - - - - - -\n";
        }
    }
}

/**
 * Iterates through all wells in _wells collection to call their update functions.
 */
void Simulation::update() {
    for (Well *well: _wells) { // for each well in the vector of wells
        well->update();
    }
}

/**
 * Iterates through all wells in _wells collections and logs their status if enabled.
 */
void Simulation::log() {
    for (Well *well: this->_wells) { // for each well in the vector of wells
        if (well->getEnabled()) {
            WellMsg *msg = new WellMsg(well); // if the well is enabled make a wellmsg object using it
            this->_display->log(msg);
            delete msg; // cleanup once we're done with the object
        }
    }
}

/**
 * Initializes _data and creates all needed wells, then passes each their relevant sensor information.
 * @param fileName Name of the file to parse.
 */
void Simulation::readFile(const char *fileName) {
    _data = OilFieldDataParser::getInstance();
    _data->initDataFile(fileName);

    for (int i = 0; i < _data->getWellCount(); i++) { // for every well that we need to initialize
        _wells.push_back(_well_factory->createWell(_data));
    }
}

/**
 * Prompts and takes input from user to enable or disable status monitoring for a well.
 */
void Simulation::editWell() {
    char *addrem = new char(); // add or remove
    char *id = new char(); // well id to search for
    bool enabled = false;

    cout << "Well ID list: \n";
    _data->printWellData();

    cout << "\nWould you like to add or remove a well from the display? [add/remove]: ";
    cin >> addrem;
    cout << "Please enter the well ID: ";
    cin >> id;

    // set enabled based on user input
    if (strcmp(addrem, "add") == 0) {
        enabled = true;
    } else if (strcmp(addrem, "remove") == 0) {
        enabled = false;
    } else {
        cout << "Error reading input, please try again.\n";
        return;
    }

    for (Well *well: _wells) { // for each well in the vector of wells TODO can optimize
        if (strcmp(well->getid(), id) == 0) { // find the well we're looking for
            well->setEnabled(enabled); // pass in user input enabled
        }
    }
}

/**
 * Prompts and takes input from user to enable or disable status monitoring for a sensor.
 */
void Simulation::editSensor() {
    char *addrem = new char();
    char *id = new char();
    char *type = new char();
    bool enabled = false;

    cout << "\nWould you like to add or remove a sensor from the display? [add/remove]: ";
    cin >> addrem;
    cout << "Please enter the well ID: ";
    cin >> id;


    if (strcmp(addrem, "add") == 0) {
        enabled = true;
    } else if (strcmp(addrem, "remove") == 0) {
        enabled = false;
    } else {
        cout << "Error reading input, please try again.\n";
        return;
    }

    for (Well *well: _wells) { // for each well in the vector of wells TODO can optimize
        if (strcmp(well->getid(), id) == 0) { // find the well we're looking for
            cout << "Please enter the sensor type from the following:\n";

            for (char *well_type: well->getSensorTypes()) {
                cout << well_type << endl; // print out all the sensor _types that the well contains
            }

            cin >> type;
            well->setEnabledSensor(type, enabled); // tell the well to set the enabled status for the sensor
        }
    }
}