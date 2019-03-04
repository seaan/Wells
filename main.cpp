/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: main.cpp
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "Simulation/Simulation.h"

Simulation *sim;
int main() {
    sim = new Simulation();
    sim->run();

    return 0;
}