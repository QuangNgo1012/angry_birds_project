#ifndef ANGRY_BIRD_LEVEL
#define ANGRY_BIRD_LEVEL
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include "box2d/box2d.h"
#include "bird.hpp"
#include "pig.hpp"
#include "object.hpp"
#include "obstacle.hpp"
#include "iostream"
#include "vector"
#include "sstream"
#include "list"
#define PPM 30.0F
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define DEG_PER_RAD 57.2957795F
class Level{

public:
/*
Constructor. Creates the Level class and sets up the Box2D world. Reads the file given in 
the input to create Birds, Obstacles & Pigs. The format of file is as follows:

Level 1
P@20@19@34@13
O@45@35@15@11


The first line stores the level name.
The following lines start with the type of object, followed by the coordinate pair  of all 
the objects of that type. Each value is separated by delimeter "@". 

*/

Level(std::ifstream& file);
/*
Creates the objects from the line in the input file of Level constructor

The vector (R, 0.3, 10, 11, 0.3, 12, 15) causes two Red birds of radius 0.3 to be created
at position (10,11) & (12,15) respectively. For birds and pigs the vector should have a length
og 3N+1 where N is the number of birds or pigs.

The vector (O, 12, 14, 19, 20) creates an obstacle whose width = 12, height = 14 at position
(19,20)

*/

void createElements(std::vector<std::string>& storage);

// Gets level name
std::string GetName() const{return name_;}

// Gets the pointer to the Box2D world
b2World* GetWorld() {return mainWorld_;}



/*

Renders the objects in the window.

*/

void RenderLevel(sf::RenderWindow &window);
/* 

Throws the Bird.

*/

void ThrowBird(Bird* bird, b2Vec2 force);
/*

Creates a circle in Box2D world

*/
b2Body* CreateCircle(float radius, float XCoord, float YCoord,float density, float friction);

/*

Creates a rectangle in Box2D world

*/


b2Body* CreateObstacle(float width, float height, float XCoord, float YCoord,float density, float friction);

protected:
/*

Stores level name.

*/
std::string name_;
// pointer to the Box2D world
b2World* mainWorld_;
// list for storing bird objects
std::list<Bird*> birdStore;
// list for storing pig objects

std::list<Pig*> pigStore;
// list for storing obstacle objects.

std::list<Obstacle*> obstacleStore;


};


#endif