//
// Created by sean on 2/4/19.
//

#ifndef WELLS_SENSOR_H
#define WELLS_SENSOR_H

#include <cstring>

struct SensorData {
    char *_type, *_class_name, *_display_name, *_units, *_abbrev, *_gen_alg, *_link;
    double _min, _max, _step;
    bool _min_undef, _max_undef;

    SensorData(char *type, char *class_name, char *display_name, char *units, char *abbrev, char *gen_alg, char *link,
               double min, double max, double step, bool min_undef, bool max_undef) {
        this->_type = new char();
        this->_class_name = new char();
        this->_display_name = new char();
        this->_units = new char();
        this->_abbrev = new char();
        this->_gen_alg = new char();
        this->_link = new char();// allocate space for all of our strings

        strcpy(this->_type, type);
        strcpy(this->_class_name, class_name);
        strcpy(this->_display_name, display_name);
        strcpy(this->_units, units);
        strcpy(this->_abbrev, abbrev);
        strcpy(this->_gen_alg, gen_alg);
        strcpy(this->_link, link); // copy the input into the member variables

        this->_min = min;
        this->_max = max;
        this->_step = step;
        this->_min_undef = min_undef;
        this->_max_undef = max_undef;
    }
};

class Sensor {
public:
    Sensor(SensorData *sensor_data);

    ~Sensor();

    void update();

    void setEnabled(bool e);

    bool getEnabled();

    char *getDisplayName();

    char *getAbbrev();

    char *getType();

    double getValue();

private:
    SensorData *_sensor_data;

    double _value;
    bool _enabled;
};


#endif //WELLS_SENSOR_H
