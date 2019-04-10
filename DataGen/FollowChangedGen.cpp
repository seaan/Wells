/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: FollowChangedGen.cpp
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include <cstdlib>
#include "FollowChangedGen.h"

/**
 *
 * @param min
 * @param max
 * @param step
 * @return
 */
double FollowChangedGen::generate(double min, double max, double step, double value, Sensor *link) {
    if (link->valueChanged())
        return min + (rand() % (int) (max - min));
    else return 0;
}
