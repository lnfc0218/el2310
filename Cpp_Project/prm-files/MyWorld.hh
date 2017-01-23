//
// = FILENAME
//    MyWorld.hh
//
// = AUTHOR(S)
//    Hui Pang
//
/*----------------------------------------------------------------------*/

#ifndef MyWorld_hh
#define MyWorld_hh


#include <iostream>
#include <list>

#include "World.hh"
#include "Obstacle.hh"

class MyWorld : public World 
{
public:
  MyWorld();
  ~MyWorld();

  bool readObstacles(std::istream &fs);
  bool collidesWith(double x, double y);
  virtual void writeMatlabDisplayCode(std::ostream &fs);

protected:
  std::list<Obstacle*> obs_list;
};

#endif
