#include "object.hpp"

Object::Object(std::string textureSource, b2Body *body) : body_(body) {
  texture_.loadFromFile(textureSource);
  sprite_.setTexture(texture_);
}

Object::Object(b2Body *body) : body_(body) {}

b2Body *Object::GetBody() { return body_; }

sf::Sprite &Object::GetSprite() { return sprite_; }

bool Object::IsFragile() { return fragile_; }

float Object::GetHP() { return hp_; }

bool Object::Broken() { return broken_; }

int Object::Attack(float attackPower) {
  if (attackPower >= hp_ && fragile_) {
    broken_ = true;
    int temp = hp_;
    hp_ = 0;

    return temp;
  } else if (attackPower < hp_ && fragile_) {
    hp_ -= attackPower;

    return attackPower;
  } else {
    return 0;
  }
}