#ifndef ANGRY_BIRDS_LEVEL
#define ANGRY_BIRDS_LEVEL
#include <string>
#include <list>
#include <vector>
#include <fstream>
#include <sstream>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include "bird.hpp"
#include <iostream>
#include <map>
#include "pig.hpp"
#include "ground.hpp"
#include "operators.hpp"
#include <iostream>
#include "obstacle.hpp"
class Level
{

public:
    // Store level using name
    Level();
    // Load level from a file
    Level(std::ifstream& file);
    // Get the box2d world
    b2World* GetWorld() {return world_;}
    // Render the level into the game's window
    bool RenderLevel(sf::RenderWindow &window);
    // Throw the bird from the slingshot
    void ThrowBird(b2Vec2 force);
    // Count the numbers of pigs in the level
    int CountPigs();
    // Check if the level is ended
    bool IsLevelEnded() { return is_ended_; }
    // Check if the level ended win or lose
    bool IsLevelWin() {return is_win_;}
    // Get the first bird in the birds_list
    Bird *GetBird() { return birds_list_.front(); }
    // Calculate the score
    int GetScore() { return score_; }
    // Set the next bird onto the slingshot
    void SetBird();

private:
    std::string name_;
    b2World* world_;
    std::list<Object *> objects_list_;
    std::list<Bird *> birds_list_;
    int score_ = 0;
    bool is_ended_ = false;
    bool is_win_ = false;
};


#endif