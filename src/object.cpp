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

void Object::MakeSound() {
  hit_sound_buffer_.loadFromFile(
      "../../resources/Sounds/Angry_Birds_Bird_Destroyed_Sound_Effect.mp3");
  hit_sound_.setBuffer(hit_sound_buffer_);
  hit_sound_.setVolume(100);
  hit_sound_.play();
}

/**void Object::SaveInfo(std::ofstream &file) {
  file << GetType() << ';';
  file << body_->GetPosition() << ';' << body_->GetAngle() << ';'
       << body_->GetLinearVelocity() << ';' << body_->GetAngularVelocity()
       << ';' << body_->GetLinearDamping() << ';' << body_->GetAngularDamping()
       << ';' << body_->GetGravityScale() << ';' << body_->GetType() << ';'
       << body_->IsAwake() << ';';
  b2Fixture *fixture = body_->GetFixtureList();
  while (fixture != nullptr) {
    b2Shape::Type collisionType = fixture->GetType();
    b2Shape *shapeData = fixture->GetShape();
    file << collisionType << ';';
    switch (collisionType) {
      // circle
      case 0:
        b2CircleShape *circle;
        circle = static_cast<b2CircleShape *>(shapeData);
        file << circle->m_p << ';' << circle->m_radius << ';';
        break;

      // polygon
      case 2:
        b2PolygonShape *polygon;
        polygon = static_cast<b2PolygonShape *>(shapeData);
        file << polygon->m_centroid << ';';
        for (auto vertices : polygon->m_vertices) {
          file << vertices << ';';
        }
        for (auto normals : polygon->m_normals) {
          file << normals << ';';
        }
        file << polygon->m_count << ';' << polygon->m_radius << ';';
        break;
    }
    file << fixture->GetDensity() << ';' << fixture->GetFriction() << ';'
         << fixture->GetRestitution() << ';';
    fixture = fixture->GetNext();
  }
}**/