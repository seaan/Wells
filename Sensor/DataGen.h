//
// Created by sean on 2/25/19.
//

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
