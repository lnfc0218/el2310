//
// = FILENAME
//    Obstacle.hh
//
// = AUTHOR(S)
//    Hui Pang
//
/*----------------------------------------------------------------------*/

#ifndef Obstacle_hh
#define Obstacle_hh

#include <vector>
#include <iostream>

class Obstacle {
public:

  Obstacle();
  virtual ~Obstacle();
  virtual bool collidesWith(double x, double y)=0;
  virtual void writeMatlabDisplayCode(std::ostream &fs);
};

#endif
