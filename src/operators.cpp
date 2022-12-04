#include "operators.hpp"

std::istream &operator>>(std::istream &input, b2Vec2 &vector)
{
    float x, y;
    char _;
    input.ignore(); 
    input >> x >> _ >> y; 
    vector.Set(x, y);
    input.ignore(); 
    return input;
}

std::istream &operator>>(std::istream &input, b2BodyType &type)
{
    int body_type;
    input >> body_type;
    switch (body_type)
    {
    case 0:
        type = b2_staticBody;
        break;
    case 1:
        type = b2_kinematicBody;
        break;
    case 2:
        type = b2_dynamicBody;
        break;
    }
    return input;
}




