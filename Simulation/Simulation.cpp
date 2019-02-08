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
//#include <sys/select.h>
//#include <unistd.h>
//#include <cstring>

void Simulation::run() {
    struct timeb struct_time;
    double current_time;
    double target_time;
    bool done = false;  // while loop flag
    char c = 0;

    srand((unsigned int)(time(NULL))); // seed srand
    readFile("../OilFieldData.xml");

    ftime(&struct_time);	// Get start struct_time
    current_time = struct_time.time + (((double)(struct_time.millitm)) / 1000.0); // Convert to double
    target_time = current_time + 5.0; // Set next 5 second interval struct_time

//    set_nonblock();
    while(!done)     // Start an eternal loop
    {
//        c = getchar();
//        if(c > 0)
//            printf("Read: %c\n", c);

        ftime(&struct_time);    // Get the current struct_time
        current_time = struct_time.time + (((double)(struct_time.millitm)) / 1000.0); // Convert to double
        // Check for 5 second interval to print status to screen
        if(current_time >= target_time)
        {
            target_time += 5.0; // Set struct_time for next 5 second interval
            update();
            log();
            cout << "- - - - - - - - - - - - - - - - - -\n";
        }
        c = 0;
        // Do other stuff here
    }

    cout << "Done";
}

void Simulation::update() {
    for(Well *well: _wells) {
        well->update();
    }
}

void Simulation::log() {
    for(Well *well: this->_wells){
        WellMsg msg(well);
        printf("%s:\n", msg.getWellInfo());
        for(char* sensor: msg.getSensorInfo()) {
            printf("\t%s\n", sensor);
        }
    }
}

void Simulation::readFile(const char *fileName) {
    OilFieldDataParser data = OilFieldDataParser("../OilFieldData.xml");

    for(int i = 0; i < data.getWellCount(); i++) {
        char *id = new char();
        char *opr = new char();
        int num_sensors;
        data.getWellData(id, opr, &num_sensors);
        Well *well = new Well(id, opr, num_sensors);
        _wells.push_back(well);
    }

    for(Well *well: _wells) {
        char *type = new char();
        char *class_name = new char();
        char *display_name = new char();
        char *units = new char();
        char *abbrev = new char();
        double min, max;

        for(int i = 0; i < well->getNumSensors(); i++) {
            data.getSensorData(well->getid(), type, class_name, display_name, &min, &max, units, abbrev);

            well->addSensor(type, class_name, display_name, units, abbrev, min, max);
        }
    }
}

//void Simulation::reset_terminal() {
//    tcsetattr(0, TCSANOW, &orig_termios);
//}
//
//void Simulation::set_nonblock() {
//    struct termios nb_termios;
//
//    tcgetattr(0, &orig_termios);
//    memcpy(&nb_termios, &orig_termios, sizeof(nb_termios));
//
//    std::atexit(reset_terminal);
//    cfmakeraw(&nb_termios);
//    tcsetattr(0, TCSANOW, &nb_termios);
//}
//
//int Simulation::kbhit() {
//    struct timeval tv = {0L, 0L};
//    fd_set fds;
//    FD_ZERO(&fds);
//    FD_SET(0, &fds);
//
//    return select(1, &fds, NULL, NULL, &tv);
//}