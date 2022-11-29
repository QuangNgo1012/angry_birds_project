#include "menu.hpp"

Menu::Menu()
{
    font_.loadFromFile("resources/font/OpenSans-Bold.ttf");
    open_ = true;
    background_image_.loadFromFile("resources/images/menu.png");
    background_.setSize(sf::Vector2f(1600, 900));
    background_.setTexture(&background_image_);
    background_.setPosition(0, 0);
};