//
// Created by seanw on 2/25/2019.
//

#include "stdafx.h"
#include "DataGenFactory.h"

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
	else return NULL;
}

DataGenFactory::DataGenFactory() {

}
