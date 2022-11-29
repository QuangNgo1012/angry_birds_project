#include "menu.hpp"

Menu::Menu()
{
    font.loadFromFile("src/font/OpenSans-Bold.ttf");
    state = true;
    background_image.loadFromFile("src/images/menu.png");
    background.setSize(sf::Vector2f(1600, 900));
    background.setTexture(&background_image);
    background.setPosition(0, 0);
};