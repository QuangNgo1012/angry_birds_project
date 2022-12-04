#ifndef ANGRY_BIRDS_PIG
#define ANGRY_BIRDS_PIG

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
      : Object("src/images/Pig.png", body) {
    int width = sprite_.getTextureRect().width;
    int height = sprite_.getTextureRect().height;

    sprite_.setScale(radius * 2.0f * 100.0f / (1.0f * width),
                     radius * 2.0f * 100.0f / (1.0f * height));
    sprite_.setOrigin(width / 2.0f, height / 2.0f);
    hp_ = 200;
    fragile_ = true;
  };

  /**
   * @brief Get the Type object
   *
   * @return char 'P'
   */
  virtual char GetType() { return 'P'; };
};

#endif