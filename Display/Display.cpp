//
// Created by sean on 2/4/19.
//

#include "Display.h"

void Display::log(WellMsg *msg) {
    *_out << msg->getWellInfo() << "\n";
    for (char *sensor: msg->getSensorInfo()) {
        *_out << "\t" << sensor << "\n";
    }
}