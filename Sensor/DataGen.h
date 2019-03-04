/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: DataGen.h
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#ifndef WELLS_DATAGEN_H
#define WELLS_DATAGEN_H


class DataGen {
public:
    DataGen(){}
    ~DataGen(){}

    virtual double generate(double min, double max, double step);
};

class RandGen : public DataGen {
public:
    double generate(double min, double max, double step);
};

class StepIncGen : public DataGen {
public:
    StepIncGen(double min);
    double generate(double min, double max, double step);
private:
    double count = 0;
};

class StepDecGen : public DataGen {
public:
    StepDecGen(double max);
    double generate(double min, double max, double step);
private:
    double count = 0;
};

class FollowGreaterGen : public DataGen {
public:
    double generate(double min, double max, double step);
};

class FollowChangedGen : public DataGen {
public:
    double generate(double min, double max, double step);
};

#endif //WELLS_DATAGEN_H
