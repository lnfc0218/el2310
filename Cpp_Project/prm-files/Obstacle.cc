//
// = FILENAME
//    Obstacle.cc
//    
// = AUTHOR(S)
//    Hui Pang
//
/*----------------------------------------------------------------------*/

#include "Obstacle.hh"

#include <iostream>
#include <vector>

Obstacle::Obstacle()
{}

Obstacle::~Obstacle()
{}

void 
Obstacle::writeMatlabDisplayCode(std::ostream &fs)
{
  std::cerr << std::endl
            << "Obstacle::writeMatlabDisplayCode not overloaded"
            << std::endl
            << "Not writing any matlab code"
            << std::endl << std::endl;
}


