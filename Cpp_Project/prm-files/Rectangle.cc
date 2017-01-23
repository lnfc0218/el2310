//
// = FILENAME
//    Rectangle.cc
//    
// = AUTHOR(S)
//    Hui Pang
//
/*----------------------------------------------------------------------*/

#include "Rectangle.hh"
#include "Obstacle.hh"

#include <iostream>
#include <cmath>

Rectangle::Rectangle(double x,double y,double w,double h,double angle)
{
  this->centerX=x;
  this->centerY=y;
  this->width=w;
  this->height=h;
  this->theta=angle;
}

Rectangle::~Rectangle()
{}

bool 
Rectangle::collidesWith(double x, double y)
{
  double dx=x-centerX;
  double dy=y-centerY;

  double ct=cos(theta);
  double st=sin(theta);

  x=ct*dx+st*dy;
  y=-st*dx+ct*dy;

  return((fabs(x)<=0.5*width)&&(fabs(y)<=0.5*height));
}

void 
Rectangle::writeMatlabDisplayCode(std::ostream &fs)
{
  fs<<"X="<<width<<"*[-.5 .5 .5 -.5 -.5];"<<"Y="<<height<<"*[.5 .5 -.5 -.5 .5];P = [X;Y];"<<"ct = cos("<<theta<<");st = sin("<<theta<<");R = [ct -st;st ct];P = R * P;plot(P(1,:)+"<<centerX<<",P(2,:)+"<<centerY<<");"<<std::endl;

}
