//
// = FILENAME
//    Circle.cc
//    
// = AUTHOR(S)
//    Hui Pang
//
/*----------------------------------------------------------------------*/

#include "Circle.hh"
#include "Obstacle.hh"

#include <iostream>
#include <cmath>

Circle::Circle(double x,double y,double r)
{
  this->centerX=x;
  this->centerY=y;
  this->radius=r;
}

Circle::~Circle()
{}

bool 
Circle::collidesWith(double x, double y)
{
  double dx=x-centerX;
  double dy=y-centerY;

  return (sqrt(dx*dx+dy*dy) <= radius);
}

void 
Circle::writeMatlabDisplayCode(std::ostream &fs)
{
  fs << "plot(" 
     << centerX<< " + " << radius << "*cos((0:5:360)/180*pi),"
     << centerY<< " + " << radius << "*sin((0:5:360)/180*pi))"
     << std::endl;
}
