#ifndef ANGRY_BIRD_BIRD
#define ANGRY_BIRD_BIRD

#include "object.hpp"

/**
 * @brief Basic class for birds.
 *
 */
class Bird : public Object {
 public:
  /**
   * @brief Construct a new Bird object
   *
   * @param textureSource Picture source of the bird object
   * @param body Box2D body with all necessary parameters
   * @param radius Radius of the bird. All bird class would be associated with a
   * circle shape.
   */
  Bird(std::string textureSource, b2Body *body, float radius);

  /**
   * @brief Sound affect for the birds
   *
   */
  void MakeSound();

  /**
   * @brief Throw the bird. The status of the bird would change to thrown.
   *
   */
  void Throw();

  /**
   * @brief Determine whether the bird has been thrown.
   *
   * @return true If is thrown.
   * @return false If is not thrown.
   */
  bool IsThrown();

  /**
   * @brief Get the Type object
   *
   * @return char See class Bird for more detail.
   */
  virtual char GetType() = 0;

  /**
   * @brief Set different parameters for defining how the bird move.
   *
   */
  virtual void Step() {}

 protected:
  // Reserved for logic design. Can be used if one bird could hit multiple
  // targets.
  int maxHP_ = 100;
  int hp_ = 0.0f;
  sf::SoundBuffer soundBuffer;
  sf::Sound sound;

  // Used to define the Box2D body of the object.
  b2Body *body_;

  // Used to define whether the bird has been thrown.
  bool thrown_ = false;

  // Used to define whether the bird has been used.
  bool exhausted_ = false;
};

/**
 * @brief Class for basic bird Red.
 *
 */
class Red : public Bird {
 public:
  /**
   * @brief Construct a new Red object
   *
   * @param body Box2D body with all parameters.
   * @param radius Radius of Red.
   */
  Red(b2Body *body, float radius);

  /**
   * @brief Set linear velocity and angular velocity for defining how Red bird
   * move.
   *
   */
  virtual void Step();

  /**
   * @brief Get the Type object
   *
   * @return char 'R'
   */
  virtual char GetType();
};

/**
 * @brief Class for speedy bird Chuck.
 *
 */
class Chuck : public Bird {
 public:
  /**
   * @brief Construct a new Chuck object
   *
   * @param body Box2D body with all parameters.
   * @param radius Radius of Chuck.
   */
  Chuck(b2Body *body, float radius);

  /**
   * @brief Set high linear velocity for defining how Chuck bird move.
   *
   */
  virtual void Step();

  /**
   * @brief Get the Type object
   *
   * @return char 'C'
   */
  virtual char GetType();
};

/**
 * @brief Class for heavy bird Terence.
 *
 */
class Terence : public Bird {
 public:
  /**
   * @brief Construct a new Terence object
   *
   * @param Box2D body with all parameters.
   * @param radius Radius of Terence.
   */
  Terence(b2Body *body, float radius);

  /**
   * @brief Set low linear velocity for defining how Terence bird move.
   *
   */
  virtual void Step();

  /**
   * @brief Get the Type object
   *
   * @return char 'T'
   */
  virtual char GetType();
};

#endif