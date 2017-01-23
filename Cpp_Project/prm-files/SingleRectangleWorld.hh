//
// = FILENAME
//    SingleRectangleWorld.hh
//
// = AUTHOR(S)
//    Hui Pang
//
/*----------------------------------------------------------------------*/

#ifndef SingleRectangleWorld_hh
#define SingleRectangleWorld_hh

#include "World.hh"

#include <string>

//#include <fstream>


class SingleRectangleWorld : public World {
public:

  


  SingleRectangleWorld();
  ~SingleRectangleWorld();

	bool readObstacles(std::istream &fs);	

  bool collidesWith(double x, double y);
  void writeMatlabDisplayCode(std::ostream &fs);

protected:

	double centerX, centerY;
	double width,height;
	double theta;
	
};

#endif // SingleRectangleWorld_hh

