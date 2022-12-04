#ifndef ANGRY_BIRDS_LEVEL_MENU
#define ANGRY_BIRDS_LEVEL_MENU

#include "menu.hpp"
#include <string>
#include <iostream>
class LevelMenu : public Menu
{
public:
    LevelMenu();
    void DrawMenu(sf::RenderWindow &window);

private:
    const static int items_number = 4;
    sf::Text items[items_number];
};

#endif
