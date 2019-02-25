//
// Created by sean on 2/25/19.
//

#ifndef WELLS_WELLFACTORY_H
#define WELLS_WELLFACTORY_H

class WellFactory {
public:
    ~WellFactory();
    static WellFactory *getInstance();
private:
    WellFactory();
};


#endif //WELLS_WELLFACTORY_H
