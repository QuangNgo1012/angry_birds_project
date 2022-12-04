#ifndef ANGRY_BIRDS_MENU
#define ANGRY_BIRDS_MENU

#include <SFML/Graphics.hpp>

class Menu
{
public:
    Menu();
    ~Menu(){}
    virtual void DrawMenu(sf::RenderWindow &window) = 0;
    // Check if the menu is open
    bool IsOpen()
    { 
        return is_open; 
    
    }
    void Close() 
    { 
        is_open = false; 
    }
    void Open() 
    { 
        is_open = true; 
    }

protected:
    bool is_open;
    sf::Font font;
    sf::Texture background_image;
    sf::RectangleShape background;
    
};

#endif