#ifndef ANGRY_BIRDS_OPERATORS
#define ANGRY_BIRDS_OPERATORS
#include <iostream>
#include <string>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <iostream>


std::istream &operator>>(std::istream &input, b2Vec2 &vector);

std::istream &operator>>(std::istream &input, b2BodyType &type);

#endif

    


