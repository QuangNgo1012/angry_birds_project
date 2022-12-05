#ifndef ANGRY_BIRD_OBJECT
#define ANGRY_BIRD_OBJECT

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

#include "box2d/box2d.h"

/**
 * @brief Basic class for all objects including birds, pig, and wall.
 *
 */
class Object {
 public:
  /**
   * @brief Construct a new Object object.
   *
   * @details Caution: Please make sure that you have input the right address
   * for the picture you want to use. If the program stuck at "Failed to load
   * image ... Reason: Unable to open file", please check the address as SFML
   * can not work properly.
   *
   * @param textureSource picture source of the object
   * @param body box2D body
   */
  Object(std::string textureSource, b2Body *body);
  Object(b2Body *body);
  virtual ~Object() {}

  /**
   * @brief Get the box2D body of the object.
   *
   * @details Can be used for accessing body data, see SaveInfo method for
   * useful data.
   *
   * @return b2Body*
   */
  b2Body *GetBody();

  /**
   * @brief Get the SFML sprite of the object.
   *
   * @details Can be used for drawing on window.
   *
   * @return sf::Sprite&
   */
  sf::Sprite &GetSprite();

  /**
   * @brief Pure virtual method for determining the type of the object (Red/
   * Chuck/ Terence/ Pig etc.)
   *
   * @return char Returns a character of type.
   * Red - 'R'
   * Chuck - 'C'
   * Terence - 'T'
   * Pig - 'P'
   */
  virtual char GetType() = 0;

  /**
   * @brief Determine whether the object can be destroyed.
   *
   * @return true - birds, pigs
   * @return false - wall
   */
  bool IsFragile();

  /**
   * @brief Virtual method for birds to initiate attack. See class Red/ Chuck/
   * Terence for more detail.
   *
   */
  virtual void Step() {}

  /**
   * @brief Check current HP.
   *
   * @return float The current HP of the object.
   */
  float GetHP();

  /**
   * @brief Determine whether the object has been destructed.
   *
   * @return true
   * @return false
   */
  bool Broken();

  /**
   * @brief Calculate attack on the objects.
   *
   * @param attackPower
   * @return int effective damage towards pigs. Can be used as points.
   */
  virtual int Attack(float attackPower);

  void MakeSound();

  // Save the object information into a file.
  // The output file is in the following order:
  // objectType(char);bodyPosition(b2Vec2);bodyAngel(float);linearVel(b2Vec2);angularVel(float);linearDamp(float);angularDamp(float);isAwake(bool);bodyShape(int);
  // if the object is a circle, then
  // position(b2Vec2);radius(float);density(float);friction(float);restitution(float);
  // if the object is a polygon, then
  // 8*centroid(b2Vec2);8*vertices(b2Vec2);count(int);radius(float);density(float);friction(float);restitution(float);
  // STILL IN DEVELOPMENT
  // void SaveInfo(std::ofstream &file);

 protected:
  // Used to store SFML sprite for the object.
  sf::Sprite sprite_;

  // Used to store the picture for the object.
  sf::Texture texture_;

  sf::SoundBuffer hit_sound_buffer_;

  sf::Sound hit_sound_;

  // Used to define whether the object can be destructed.
  bool fragile_ = false;

  // Used to define the hp of the object.
  int hp_ = 100;

 private:
  // Used to define the Box2D body of the object.
  b2Body *body_;

  // Used to define whether the object is broken (hp == 0).
  bool broken_ = false;
};

#endif