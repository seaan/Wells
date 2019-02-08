//
// Created by sean on 2/4/19.
//

#ifndef WELLS_SENSOR_H
#define WELLS_SENSOR_H


class Sensor {
public:
    Sensor(char *type, char *class_name, char *display_name, char *units, char *abbrev, double min, double max);
    ~Sensor();

    void update();
    char* getDisplayName();
    char* getAbbrev();
    double getValue();

private:
    char *_type, *_class_name, *_display_name, *_units, *_abbrev;
    double _min, _max, _value;

    bool _enabled;
};


#endif //WELLS_SENSOR_H
