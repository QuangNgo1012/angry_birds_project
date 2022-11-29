#ifndef ANGRY_BIRDS_MENU
#define ANGRY_BIRDS_MENU

#include <SFML/Graphics.hpp>

class Menu
{
public:
    Menu();
    ~Menu(){}
    virtual void DrawMenu(sf::RenderWindow &window) = 0;
    bool IsOpen()
    { 
        return state; 
    
    }
    void CloseMenu() 
    { 
        state = false; 
    }
    void OpenMenu() 
    { 
        state = true; 
    }

protected:
    bool state;
    sf::Font font;
    sf::Texture background_image;
    sf::RectangleShape background;
    
};

#endif