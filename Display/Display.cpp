/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Display.cpp
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "stdafx.h"
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