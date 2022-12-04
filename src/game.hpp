#ifndef ANGRY_BIRDS_GAME
#define ANGRY_BIRDS_GAME

#include "menu_start.hpp"
#include "menu_lose.hpp"
#include "menu_win.hpp"
#include "menu_level.hpp"
#include "level.hpp"
#include "operators.hpp"

class Game
{
public:
    Game();
    //Start the game
    void Start();
    //Load a level using file name.
    void LoadLevel(std::string filename){
        std::ifstream file(filename);
        current_level_file_name_ = filename;
        current_level_ = Level(file);
    }

private:
    std::string current_level_file_name_;
    Level current_level_;
    sf::RenderWindow window_;
    sf::Texture background_texture_;
    sf::Sprite bg_sprite_;
};

#endif