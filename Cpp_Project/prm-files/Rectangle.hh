//
// = FILENAME
//    Rectangle.hh
//
// = AUTHOR(S)
//    Hui Pang
//
/*----------------------------------------------------------------------*/

#ifndef Rectangle_hh
#define Rectangle_hh


#include <vector>
#include <iostream>

#include "Obstacle.hh"



class Rectangle:public Obstacle{
public:

  Rectangle(double x,double y,double w,double h,double angle);
  ~Rectangle();

  bool collidesWith(double x, double y);

  void writeMatlabDisplayCode(std::ostream &fs);

protected:

  double centerX,centerY;
  double width,height;
  double theta;

};
#endif
