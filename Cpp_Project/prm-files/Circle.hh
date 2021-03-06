//
// = FILENAME
//    Circle.hh
//
// = AUTHOR(S)
//    Hui Pang
//
/*----------------------------------------------------------------------*/

#ifndef Circle_hh
#define Circle_hh

#include <vector>
#include <iostream>

#include "Obstacle.hh"

class Circle:public Obstacle
{
public:

  Circle(double x,double y,double r);

  ~Circle();

bool collidesWith(double x, double y);

void writeMatlabDisplayCode(std::ostream &fs);


protected:

  double centerX,centerY;
  double radius;
};

#endif
