#include <iostream>
#include <fstream>
#include <string>

#include "Constants.h"
#include "Utilities.h"
#include "MassMean.h"
#include "Event.h"

float massMinK0 = 0.490;
float massMaxK0 = 0.505;
float massMinL0 = 1.114;
float massMaxL0 = 1.118;

const Event* read( std::ifstream& file );
void         dump( const Event& ev );

int main( int argc, char* argv[] ) {

  // open input file
  std::string name = argv[1];
  std::ifstream file( name.c_str() );

  // create MassMean objects
  MassMean K0     ( massMinK0, massMaxK0 );
  MassMean Lambda0( massMinL0, massMaxL0 );

  const Event* ev;

  // loop over events
  while ( ( ev = read( file ) ) != 0 ) {
    dump( *ev );

    K0.add( *ev );
    Lambda0.add( *ev );

  }

  // compute results
  K0.compute();
  Lambda0.compute();

  // print number of selected events and results for both particles
  std::cout << K0.nEvents()      << ' ' << K0.mMeanM() 
                                 << ' ' << K0.mRMS() << std::endl;
  
  std::cout << Lambda0.nEvents() << ' ' << Lambda0.mMeanM() 
                                 << ' ' << Lambda0.mRMS()    << std::endl;
  

  return 0;

}