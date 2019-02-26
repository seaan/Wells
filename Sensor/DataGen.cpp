//
// Created by sean on 2/25/19.
//

#include <cstdlib>
#include "DataGen.h"

/**
 *
 * @param min
 * @param max
 * @param step
 * @return
 */
double DataGen::generate(double min, double max, double step, double value, Sensor *link) {
    return -1;
}

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

/**
 *
 * @param min
 * @param max
 * @param step
 * @return
 */
double StepIncGen::generate(double min, double max, double step, double value, Sensor *link) {
    if (value < max)
        value += (rand() % (int) (step + 1));
    return value;
}

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