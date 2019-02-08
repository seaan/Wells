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

    std::vector<Well*> _wells;
    Display *_display;

//    struct termios orig_termios;
//
//    void set_nonblock();
//    static void reset_terminal();
//    int kbhit();
};


#endif //WELLS_SIMULATION_H
