//
// Created by sean on 2/4/19.
//

#ifndef WELLS_SIMULATION_H
#define WELLS_SIMULATION_H

#include "../Well/Well.h"
#include "../Display/Display.h"

#include <termios.h>

class Simulation {
public:
    Simulation(){
        _display = new Display();

    }

    void run();
private:
    void update();
    void log();

    void readFile(const char *fileName);

    void editWell();
    void editSensor();

    std::vector<Well*> _wells;
    Display *_display;
    OilFieldDataParser *_data;
};


#endif //WELLS_SIMULATION_H
