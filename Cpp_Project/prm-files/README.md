implement a world model for the Probabilistic Road Maps(PRM) algorithm to query if a certain point in space is free from obstacles. 

Check project description [here](http://www.nada.kth.se/~yaseminb/cplusplus.html)

## Files added by me:

|File Name                      |Aim                                |
|:-----------------------------:|-----------------------------------|
|SingleRectangleWorld.hh[cc]	  | Intermediate product for testing  |
|MyWorld.hh[cc]			           	| Read problem files, answer queries|
|Obstacle.hh[cc]			        	| Base class for obstacles          |
|Circle.hh[cc]		           		| Subclass for circle obstacles     |
|Rectangle.hh[cc]	          		| Subclass for rectangle obstacles  |

## Files from the original PRM package:

|File Name                      |Aim                                |
|:-----------------------------:|-----------------------------------|
|README                         | This file                         |
|solvePlanningProblem.cc        | The main program                  |
|Position.hh[cc]                | Position (x,y)                    |
|AStarNode.hh[cc]               | Node in a graph to use A*-search  |
|PRM.hh[cc]                     | Simple implementation of PRM      |
|PRMNode.hh[cc]                 | Node in the road map              |
|World.hh[cc]                   | Base class for obstacles          |
|SingleCircleWorld.hh[cc]       | Simple example of a world         |
|problem1.txt                   | example world obstacle specification file|
|problem2.txt                   | example world obstacle specification file|
|problem3.txt                   | example world obstacle specification file|
|plan_singlecircle.png          | example execution result with SingleCircleWorld|
|plan_problem1.png              | example execution of problem1.txt |
|plan_problem2.png              | example execution of problem2.txt |
|plan_problem3.png              | example execution of problem3.txt |



