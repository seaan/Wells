/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: RandGen.cpp
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include <cstdlib>
#include "RandGen.h"

/**
 *
 * @param min
 * @param max
 * @param step
 * @return
 */
double RandGen::generate(double min, double max, double step, double value, Sensor *link) {
    return min + (rand() % (int) (max - min));
}