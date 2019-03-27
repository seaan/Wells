//
// Created by seanw on 2/25/2019.
//

#ifndef WELLS_DATAGENFACTORY_H
#define WELLS_DATAGENFACTORY_H


#include "DataGen.h"

class DataGenFactory {
public:
    ~DataGenFactory();

    static DataGenFactory *getInstance();

    DataGen *createDataGen(char *gen_alg, double *init_value, double max, double min);

private:
    DataGenFactory();
};


#endif //WELLS_DATAGENFACTORY_H
