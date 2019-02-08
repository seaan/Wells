//
// Created by sean on 2/4/19.
//

#include "Display.h"

void Display::log(WellMsg msg) {
    printf("%s\n", msg.getWellInfo());
    for(char* sensor: msg.getSensorInfo()) {
        printf("\t%s\n", sensor);
    }
}