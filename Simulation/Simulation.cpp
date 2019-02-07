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

void Simulation::run() {
    struct timeb time;
    double current_time;
    double target_time;
    bool done = false;  // while loop flag
    char c = 0;

    OilFieldDataParser data = OilFieldDataParser("../OilFieldData.xml");
    data.printWellData();

    ftime(&time);	// Get start time
    current_time = time.time + (((double)(time.millitm)) / 1000.0); // Convert to double
    target_time = current_time + 5.0; // Set next 5 second interval time

    set_nonblock();
    while(!done)     // Start an eternal loop
    {
        c = getchar();
        if(c > 0)
            printf("Read: %c\n", c);

        ftime(&time);    // Get the current time
        current_time = time.time + (((double)(time.millitm)) / 1000.0); // Convert to double
        // Check for 5 second interval to print status to screen
        if(current_time >= target_time)
        {
            target_time += 1.0; // Set time for next 5 second interval
            cout << "One\n";
        }
        c = 0;
        // Do other stuff here
    }

    cout << "Done";
}

void Simulation::reset_terminal() {
    tcsetattr(0, TCSANOW, &orig_termios);
}

void Simulation::set_nonblock() {
    struct termios nb_termios;

    tcgetattr(0, &orig_termios);
    memcpy(&nb_termios, &orig_termios, sizeof(nb_termios));
    
    std::atexit(reset_terminal);
    cfmakeraw(&nb_termios);
    tcsetattr(0, TCSANOW, &nb_termios);
}

int Simulation::kbhit() {
    struct timeval tv = {0L, 0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);

    return select(1, &fds, NULL, NULL, &tv);
}