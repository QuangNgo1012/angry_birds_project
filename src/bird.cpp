#include "bird.hpp"
#include <iostream>

Bird::Bird(std::string textureSource, b2Body *body, float radius)
    : Object(textureSource, body) {
  body_ = body;
  int width = sprite_.getTextureRect().width;
  int height = sprite_.getTextureRect().height;
  sprite_.setScale(radius * 2.0f * 100.0f / (1.0f * width),
                   radius * 2.0f * 100.0f / (1.0f * width));
  sprite_.setOrigin(width / 2.0f, height / 2.0f);
}

void Bird::Throw() { thrown_ = true; }

bool Bird::IsThrown() { return thrown_; }

Red::Red(b2Body *body, float radius)
    : Bird("src/images/Red.png", body, radius) {}

void Red::Step() {
  if (mana_left_ > 0)
        {
            mana_left_ =mana_left_-5;
            body_->SetAngularVelocity(0);
            body_->SetLinearVelocity(body_->GetLinearVelocity() + b2Vec2(5, 5));

        }
}

char Red::GetType() { return 'R'; }

Chuck::Chuck(b2Body *body, float radius)
    : Bird("src/images/Chuck.png", body, radius) {}

void Chuck::Step() {
  if (mana_left_ > 0)
        {
            mana_left_--;
            body_->SetLinearVelocity(body_->GetLinearVelocity() +
                           body_->GetLinearVelocity());

        }
}

char Chuck::GetType() { return 'C'; }

Terence::Terence(b2Body *body, float radius)
    : Bird("src/images/Terence.png", body, radius) {}

void Terence::Step() {
  if (mana_left_ > 0)
        {
            mana_left_--;
            body_->SetLinearVelocity(body_->GetLinearVelocity() - b2Vec2(1.0, 1.0));
        }
}

char Terence::GetType() { return 'T'; }