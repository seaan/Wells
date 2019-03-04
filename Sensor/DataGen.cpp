/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: DataGen.cpp
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include <cstdlib>
#include "DataGen.h"

/**
 *
 * @param min
 * @param max
 * @param step
 * @return
 */
double DataGen::generate(double min, double max, double step) {
    return -1;
}

/**
 *
 * @param min
 * @param max
 * @param step
 * @return
 */
double RandGen::generate(double min, double max, double step) {
    return min + (rand() % (int) (max - min));
}

/**
 *
 * @param min
 */
StepIncGen::StepIncGen(double min) {
    this->count = min;
}

/**
 *
 * @param min
 * @param max
 * @param step
 * @return
 */
double StepIncGen::generate(double min, double max, double step) {
    if (this->count < max)
        this->count += (rand() % (int) (step+1));
    return this->count;
}

/**
 *
 * @param max
 */
StepDecGen::StepDecGen(double max) {
    this->count = max;
}

/**
 *
 * @param min
 * @param max
 * @param step
 * @return
 */
double StepDecGen::generate(double min, double max, double step) {
    if (this->count > min)
        this->count -= (rand() % (int) (step+1));
    return this->count;
}

/**
 *
 * @param min
 * @param max
 * @param step
 * @return
 */
double FollowGreaterGen::generate(double min, double max, double step) {
    return DataGen::generate(0, 0, 0);
}

/**
 *
 * @param min
 * @param max
 * @param step
 * @return
 */
double FollowChangedGen::generate(double min, double max, double step) {
    return DataGen::generate(0, 0, 0);
}