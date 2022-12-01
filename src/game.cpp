#include "game.hpp"
#include <string>

Game::Game() : window_(sf::VideoMode(1600, 900), "Angry Birds")
{
    window_.setFramerateLimit(60);
}

void Game::Start()
{
    sf::View game_view(window_.getDefaultView());
    StartMenu start_menu = StartMenu();
    LoseMenu lose_menu = LoseMenu();
    WinMenu win_menu = WinMenu();
    sf::Clock clock;

    std::ifstream file("src/levels/level1.txt");
    Level level1 = Level(file);

    while (window_.isOpen())
    {
        sf::Vector2f mouse_position = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));
        sf::Event event;
        while (window_.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::EventType::Closed:
                window_.close();
                break;
            case sf::Event::EventType::MouseButtonPressed:
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    std::cout<<mouse_position.x<<","<<mouse_position.y<<std::endl;
                    if (mouse_position.x >= 58 && mouse_position.x <= 225 && mouse_position.y >= 424 && mouse_position.y <= 481)
                    {
                        window_.close();
                        break;
                    }
                }
            }
        }
        
        level1.RenderLevel(window_);
        window_.display();
        
    }
    
}
        
            
