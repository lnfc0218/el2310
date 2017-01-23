# -----------
# Variables
# -----------

# Define compiler
CC = g++
# External libraries to include
LDLIBS = 
# Header files to include
INCLUDES = 
# Flags for compiler
CCFLAGS = -Wall
# Flags for linker
LDFLAGS = 

MAIN=main
MAIN_OBJS=solvePlanningProblem.cc Position.cc PRM.cc PRMNode.cc AStarNode.cc World.cc SingleCircleWorld.cc SingleRectangleWorld.cc MyWorld.cc Obstacle.cc Circle.cc Rectangle.cc

$(MAIN): $(MAIN_OBJS) 
	$(CC) $(CFLAGS) -o $(MAIN) $(MAIN_OBJS) $(LIBS)

clean: 
	rm -f *.o $(MAIN)

debug:
	$(CC)  $(CFLAGS) -o $(MAIN) $(MAIN_OBJS) $(LIBS) -g
