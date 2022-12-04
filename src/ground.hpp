#ifndef ANGRY_BIRDS_GROUND
#define ANGRY_BIRDS_GROUND
#include "object.hpp"

class Ground : public Object
{
public:
    Ground(b2Body *body) : Object("src/images/ground.png", body)
    {
        float w = static_cast<float>(sprite_.getTextureRect().width);
        float h = static_cast<float>(sprite_.getTextureRect().height);
        sprite_.setScale(50.0f * 64.0f / w, 10.0f * 64.0f / h);
        texture_.setRepeated(true);
        sprite_.setTextureRect({0, 0, static_cast<int>(100 * 100.0f), static_cast<int>(6 * 100.0f)});
        sprite_.setOrigin(0, 150);
    };

    virtual char GetType() { return 'G'; };
    int Attack(float power)
    {
        return 0;
    }

private:
};

#endif 