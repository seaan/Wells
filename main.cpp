#include "Simulation/Simulation.h"

Simulation *sim;
int main() {
    sim = new Simulation();
    sim->run();

    return 0;
}