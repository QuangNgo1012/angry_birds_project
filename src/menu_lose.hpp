#ifndef ANGRY_BIRDS_LOSE_MENU
#define ANGRY_BIRDS_LOSE_MENU

#include "menu.hpp"
#include <string>
#include <iostream>
class LoseMenu : public Menu
{
public:
    LoseMenu();
    void DrawMenu(sf::RenderWindow &window);

private:
    const static int items_number = 3;
    sf::Text items[items_number];
};

#endif

