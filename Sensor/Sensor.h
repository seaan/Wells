//
// Created by sean on 2/4/19.
//

#ifndef WELLS_SENSOR_H
#define WELLS_SENSOR_H


class Sensor {
public:
    Sensor();
    void update();
private:
    void *_data;
    bool _enabled;
};


#endif //WELLS_SENSOR_H
