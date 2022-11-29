#ifndef ANGRY_BIRDS_WIN_MENU
#define ANGRY_BIRDS_WIN_MENU

#include "menu.hpp"
#include <string>
#include <iostream>
class WinMenu : public Menu
{
public:
    WinMenu();
    void DrawMenu(sf::RenderWindow &window);

private:
    const static int items_number = 3;
    sf::Text items[items_number];
};

#endif

