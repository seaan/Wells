//
// Created by sean on 2/25/19.
//

#include "WellFactory.h"

WellFactory::~WellFactory() {

}

WellFactory *WellFactory::getInstance() {
    static WellFactory *instance = nullptr;
    if(instance == nullptr)
        instance = new WellFactory();
    return instance;
}

WellFactory::WellFactory() {
    _sensor_factory = SensorFactory::getInstance();
}

Well *WellFactory::createWell(OilFieldDataParser *data) {
    // Well variables
    char *id = new char[32];
    char *opr = new char[32];
    int num_sensors;
    char ***types = new char**;

    // Sensor variables
    char *class_name = new char[32];
    char *display_name = new char[32];
    char *units = new char[32];
    char *abbrev = new char[32];
    char *gen_alg = new char[32];
    char *link = new char[32];
    double min, max, step;
    bool min_undef, max_undef;

    // Well creation
    data->getWellData(id, opr, &num_sensors, types); // use getWellData to populate our variables
    Well *well = new Well(id, opr, num_sensors); // create a new Well object using the variables

    // Well sensor population
    for (int i = 0; i < well->getNumSensors(); i++) {
        data->getSensorData((*types)[i], class_name, display_name, &min, &min_undef, &max, &max_undef, &step, units,
                            abbrev, gen_alg, link);
        _sensor_factory->defineType(
                new SensorConfig((*types)[i], class_name, display_name, units, abbrev, gen_alg, link, min, max, step,
                               min_undef, max_undef)); // add this type to the sensor factory

        well->addSensor(_sensor_factory->createSensor(
                (*types)[i])); // grab a sensor of the type we need and put it into the vector of sensors
    }

    return well;
}
