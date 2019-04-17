/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: FollowChangedGen.h
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#ifndef WELLS_FOLLOWCHANGEDGEN_H
#define WELLS_FOLLOWCHANGEDGEN_H

#include "DataGen.h"

class FollowChangedGen : public DataGen {
public:
    double generate(double min, double max, double step, double value, Sensor *link);
};


#endif //WELLS_FOLLOWCHANGEDGEN_H
