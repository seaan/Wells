/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: StepDecGen.cpp
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include <cstdlib>
#include "StepDecGen.h"

/**
 *
 * @param min
 * @param max
 * @param step
 * @return
 */
double StepDecGen::generate(double min, double max, double step, double value, Sensor *link) {
    if (value > min)
        value -= (rand() % (int) (step + 1));
    return value;
}