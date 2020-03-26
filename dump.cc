// Created by Aidin Attar. 2019

// dump.cc

#include <iostream>

#include "Event.h"

void dump( const Event& ev ){

    // write event number, 3 decay point coordinates and number
    // of particles
    std::cout << ev.eventNumber() << std::endl
              << ev.getX() << ' '
              << ev.getY() << ' '
              << ev.getZ() << std::endl
              << ev.numParticles() << std::endl;

    // write charge and 3 momentum components for every particle
    for( int i = 0; i < ev.numParticles(); ++i)
        std::cout << ev.particle( i )->q  << ' '
                  << ev.particle( i )->Px << ' '
                  << ev.particle( i )->Py << ' '
                  << ev.particle( i )->Pz << std::endl;

    return;
}