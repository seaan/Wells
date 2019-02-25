//
// Created by sean on 2/4/19.
//

#ifndef WELLS_SENSOR_H
#define WELLS_SENSOR_H

struct SensorData {
    char *_type, *_class_name, *_display_name, *_units, *_abbrev, *gen_alg, *link;
    double _min, _max, step;
    bool min_undef, max_undef;
};

class Sensor {
public:
    Sensor(SensorData sensor_data);

    ~Sensor();

    void update();

    void setEnabled(bool e);

    bool getEnabled();

    char *getDisplayName();

    char *getAbbrev();

    char *getType();

    double getValue();

private:
    SensorData _sensor_data;

    double _value;
    bool _enabled;
};


#endif //WELLS_SENSOR_H
