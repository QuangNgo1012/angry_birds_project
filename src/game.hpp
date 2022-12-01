#ifndef ANGRY_BIRDS_GAME
#define ANGRY_BIRDS_GAME

#include "menu_start.hpp"
#include "menu_lose.hpp"
#include "menu_win.hpp"
#include "level.hpp"

class Game
{
    public:
    Game();
    void Start();

private:

    sf::RenderWindow window_;
    sf::Texture background_texture;
    sf::Sprite bg_sprite;
};

#endif