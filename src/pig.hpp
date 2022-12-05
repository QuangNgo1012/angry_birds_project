#ifndef ANGRY_BIRD_PIG
#define ANGRY_BIRD_PIG

#include "object.hpp"

/**
 * @brief Class for basic Pig.
 *
 */
class Pig : public Object {
 public:
  /**
   * @brief Construct a new Pig object
   *
   * @param body Box2D body with all parameters.
   * @param radius Radius of Pig.
   */
  Pig(b2Body *body, float radius)
      : Object("../../resources/images/Pig.png", body) {
    int width = sprite_.getTextureRect().width;
    int height = sprite_.getTextureRect().height;

    sprite_.setScale(radius * 2.0f * 100.0f / (1.0f * width),
                     radius * 2.0f * 100.0f / (1.0f * height));
    sprite_.setOrigin(width / 2.0f, height / 2.0f);
    hp_ = 500;
    fragile_ = true;
  };

  /**
   * @brief Get the Type object
   *
   * @return char 'P'
   */
  virtual char GetType() { return 'P'; };

  void MakeSound() {
    hit_sound_buffer_.loadFromFile(
        "../../resources/Sounds/Angry_Birds_Bird_Destroyed_Sound_Effect.mp3");
    hit_sound_.setBuffer(hit_sound_buffer_);
    hit_sound_.setVolume(20);
    pig_sound_buffer_.loadFromFile(
        "../../resources/Sounds/Angry_Birds_Piglets_Sound_Effect.mp3");
    pig_sound_.setBuffer(pig_sound_buffer_);
    pig_sound_.setVolume(20);
    hit_sound_.play();
    pig_sound_.play();
  }

 private:
  sf::SoundBuffer pig_sound_buffer_;
  sf::Sound pig_sound_;
};

#endif