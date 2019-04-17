/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: DataGenFactory.cpp
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "DataGenFactory.h"
#include "RandGen.h"
#include "StepIncGen.h"
#include "StepDecGen.h"
#include "FollowGreaterGen.h"
#include "FollowChangedGen.h"

DataGenFactory::~DataGenFactory() {

}

DataGenFactory *DataGenFactory::getInstance() {
    static DataGenFactory *instance = nullptr;
    if (instance == nullptr)
        instance = new DataGenFactory();
    return instance;
}

DataGen *DataGenFactory::createDataGen(char *gen_alg, double *init_value, double max, double min) {
    if (strcmp(gen_alg, "RAND_MIN2MAX") == 0) {
        return new RandGen();
    }
    if (strcmp(gen_alg, "STEPINC_MIN2MAX") == 0) {
        *init_value = min;
        return new StepIncGen();
    }
    if (strcmp(gen_alg, "STEPDEC_MAX2MIN") == 0) {
        *init_value = max;
        return new StepDecGen();
    }
    if (strcmp(gen_alg, "FOLLOWLINK_IFGREATER") == 0) {
        return new FollowGreaterGen();
    }
    if (strcmp(gen_alg, "FOLLOWLINK_IFCHANGED") == 0) {
        return new FollowChangedGen();
    }
}

DataGenFactory::DataGenFactory() {

}
