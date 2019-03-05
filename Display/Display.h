/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Display.h
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#ifndef WELLS_DISPLAY_H
#define WELLS_DISPLAY_H

#include "../Well/WellMsg.h"
#include <iostream>

class Display {
public:
    Display(std::ostream *out) {
        _out = out;
    }

    void log(WellMsg *msg);

private:
    std::ostream *_out;
};


#endif //WELLS_DISPLAY_H
