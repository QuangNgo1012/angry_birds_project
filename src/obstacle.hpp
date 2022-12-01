#ifndef ANGRY_BIRD_OBSTACLE
#define ANGRY_BIRD_OBSTACLE

#include "object.hpp"

/**
 * @brief Class for basic wood box obstacle
 *
 */
class Obstacle : public Object {
 public:
  /**
   * @brief Construct a new Obstacle object
   *
   * @param body Box2D body with all parameters.
   * @param blockWidth Desired width of the box.
   * @param blockHeight Desired height of the box.
   */
  Obstacle(b2Body *body, float blockWidth, float blockHeight)
      : Object("src/images/Wood.png", body) {
    int width = sprite_.getTextureRect().width;
    int height = sprite_.getTextureRect().height;

    sprite_.setScale(blockWidth * 2.0f * 100.0f / (1.0f * width),
                     blockHeight * 2.0f * 100.0f / (1.0f * height));
    sprite_.setOrigin(width / 2.0f, height / 2.0f);

    hp_ = 500;
    fragile_ = true;
  };

  /**
   * @brief Get the Type object
   *
   * @return char 'O'
   */
  char GetType() { return 'O'; };
};

#endif