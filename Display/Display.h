//
// Created by sean on 2/4/19.
//

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
