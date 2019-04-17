/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: FollowGreaterGen.cpp
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "FollowGreaterGen.h"

/**
 *
 * @param min
 * @param max
 * @param step
 * @return
 */
double FollowGreaterGen::generate(double min, double max, double step, double value, Sensor *link) {
    if (value < link->getValue()) return link->getValue();
    else return value;
}