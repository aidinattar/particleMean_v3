// Created by Aidin Attar. 2019

// read.cc

#include <iostream>
#include <fstream>

#include "Event.h"

const Event* read( std::ifstream& file ){

    // pointers to objects
    Event* ev;
    int i;
    float  x,  y,  z;
    int q;
    float Px, Py, Pz;

    // try to read input file
    if (file >> i){

        file      >>  x >>  y >>  z;
        ev = new Event( i,
                        x, y, z );// on success create new event

    }
    else return 0; // on failure return null pointer

    // read and store number of points
    int n;
    file >> n;

    for( i = 0; i < n; ++i ){

        file >> q 
             >> Px >> Py >> Pz;

        ev->add( Px, Py, Pz, q );
    }

    return ev;
}