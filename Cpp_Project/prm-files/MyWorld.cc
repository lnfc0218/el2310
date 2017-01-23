//
// = FILENAME
//    MyWorld.cc
//    
// = AUTHOR(S)
//    Hui Pang
//
/*----------------------------------------------------------------------*/

#include "MyWorld.hh"

#include <iostream>
#include <string>
#include <cmath>

//#include <list>


#include "World.hh"
#include "Obstacle.hh"
#include "Rectangle.hh"
#include "Circle.hh"


MyWorld::MyWorld()
{}
MyWorld::~MyWorld() 
{}

bool
MyWorld::collidesWith(double x, double y)
{
  std::list<Obstacle*>::iterator i;
  bool flag;
  for(i=obs_list.begin();i!=obs_list.end();++i)
    {
      Obstacle *obs=*i;

      flag=obs->collidesWith(x,y);

      if (true==flag)
	return(flag);
    }
  return 0;
}

bool 
MyWorld::readObstacles(std::istream &fs)
{
  std::string shape;
  double x,y,w,h,a,r;
  while(!fs.eof())
    {
      fs>>shape;
      if("CIRCLE"==shape)
	{
	  fs>>x>>y>>r;
	  obs_list.push_back(new Circle(x,y,r));
	}
      else if("RECTANGLE"==shape)
	{
	  fs>>x>>y>>w>>h>>a;
	  obs_list.push_back(new Rectangle(x,y,w,h,a));
	}
    }
  return 1;
}

void 
MyWorld::writeMatlabDisplayCode(std::ostream &fs)
{
  std::list<Obstacle*>::iterator i;
  for(i=obs_list.begin();i!=obs_list.end();++i)
    {
      Obstacle *obs=*i;
      obs->writeMatlabDisplayCode(fs);
    }
}
