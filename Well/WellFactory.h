//
// Created by sean on 2/25/19.
//

#ifndef WELLS_WELLFACTORY_H
#define WELLS_WELLFACTORY_H

#include "../Utility/OilFieldDataParser.h"
#include "Well.h"

class WellFactory {
public:
    ~WellFactory();

    static WellFactory *getInstance();

    Well *createWell(OilFieldDataParser *data);

private:
    WellFactory();

    SensorFactory *_sensor_factory;
};


#endif //WELLS_WELLFACTORY_H
