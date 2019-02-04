//
// Created by sean on 2/4/19.
//

#ifndef WELLS_SIMULATION_H
#define WELLS_SIMULATION_H

#include "../Well/Well.h"
#include "../Display/Display.h"

class Simulation {
public:
    Simulation();
    void run();
private:
    std::vector<Well> _wells;
    Display *_display;
};


#endif //WELLS_SIMULATION_H
