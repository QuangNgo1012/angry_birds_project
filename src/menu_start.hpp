#ifndef ANGRY_BIRDS_START_MENU
#define ANGRY_BIRDS_START_MENU

#include "menu.hpp"
#include <string>

class StartMenu : public Menu
{
public:
    StartMenu();
    void DrawMenu(sf::RenderWindow &window);

private:
    const static int items_number = 2;
    sf::Text items[items_number];
};

#endif