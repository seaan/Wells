//
// Created by sean on 2/4/19.
//

#include "Display.h"

/**
 * Prints well information and all sensor information for that well to _out.
 * @param msg WellMsg object containing information to be displayed.
 */
void Display::log(WellMsg *msg) {
    *_out << msg->getWellInfo() << "\n";
    for (char *sensor: msg->getSensorInfo()) {
        *_out << "\t" << sensor << "\n";
    }
}