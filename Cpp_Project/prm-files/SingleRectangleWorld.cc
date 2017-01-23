//
// = FILENAME
//    SingleRectangleWorld.cc
//    
// = AUTHOR(S)
//    Hui Pang
//
/*----------------------------------------------------------------------*/

#include "SingleRectangleWorld.hh"

#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

SingleRectangleWorld::SingleRectangleWorld()
{
}

SingleRectangleWorld::~SingleRectangleWorld()
{}


bool
SingleRectangleWorld::readObstacles(std::istream &fs)
{

  std::string shape;

  double x,y,w,h,r,a;


  while(!fs.eof())
    {

fs>>shape;




      if("CIRCLE"==shape)
	{
	  fs>>x>>y>>r;

	}
      else if("RECTANGLE"==shape)
	{
	  fs>>x>>y>>w>>h>>r;
	this->centerX=x;
	this->centerY=y;
	this->width=w;
	this->height=h;
	this->theta=a;

	}
	}
	return 1;

}


bool 
SingleRectangleWorld::collidesWith(double x, double y)
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
SingleRectangleWorld::writeMatlabDisplayCode(std::ostream &fs)
{

	fs<<"X="<<width<<"*[-.5 .5 .5 -.5 -.5];"<<"Y="<<height<<"*[.5 .5 -.5 -.5 .5];P = [X;Y];"<<"ct = cos("<<theta<<");st = sin("<<theta<<");R = [ct -st;st ct];P = R * P;plot(P(1,:)+"<<centerX<<",P(2,:)+"<<centerY<<");"<<std::endl;
}

