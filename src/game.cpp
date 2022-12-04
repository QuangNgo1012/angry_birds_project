#include "game.hpp"
#include <string>

Game::Game() : window_(sf::VideoMode(1600, 900), "Angry Birds")
{
    window_.setFramerateLimit(60);
}

void Game::Start()
{

    bool stable = false;           
    bool is_stable = stable; 
    float angle = 0;            
    float power = 0;                 
    background_texture_.loadFromFile("src/images/background.png");
    background_texture_.setRepeated(true);
    bg_sprite_.setTexture(background_texture_);
    bg_sprite_.setTextureRect({0, 0,1600 * 10, 900 * 10});
    bg_sprite_.setScale(1, 3);
    bg_sprite_.setOrigin(0,945);
    sf::Font font;
    font.loadFromFile("src/font/OpenSans-Bold.ttf");
    sf::Text score;
    score.setFont(font);
    score.setFillColor(sf::Color::White);
    score.setOutlineColor(sf::Color::Black);
    score.setOutlineThickness(3.0f);
    score.setString(std::string("Score: ") + std::to_string(current_level_.GetScore()));
    score.setCharacterSize(50);
    sf::View game_view(window_.getDefaultView());
    StartMenu start_menu = StartMenu();
    LoseMenu lose_menu = LoseMenu();
    WinMenu win_menu = WinMenu();
    LevelMenu level_menu =LevelMenu();
    auto IsMenuOpen = [&]()
    {
        return start_menu.IsOpen() || win_menu.IsOpen() || lose_menu.IsOpen() || level_menu.IsOpen() ;
    };
    LoadLevel("src/levels/level1.txt");
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
                    if (current_level_.GetBird()->IsThrown() && !IsMenuOpen())
                    {
                        
                        current_level_.GetBird()->UsePower();
                    }
                    else if (stable && !IsMenuOpen() && power != 0)
                    {
                        float x = cos(angle* (M_PI / 180.0f)) * power / 20;
                        float y = sin(angle* (M_PI / 180.0f)) * power / 20;
                        current_level_.ThrowBird(b2Vec2(x, y));
                    }
                }
                break;
            }
        }
        window_.clear(sf::Color::Blue);
        window_.draw(bg_sprite_);
        if (start_menu.IsOpen())
        {
            level_menu.Open();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                
                if (mouse_position.x >= 52 && mouse_position.x <= 246 && mouse_position.y >= 223 && mouse_position.y <= 280)
                {
                    start_menu.Close();
                }
                else if (mouse_position.x >= 52 && mouse_position.x <= 226 && mouse_position.y >= 427 && mouse_position.y <= 477)
                {
                    window_.close();
                }
            }
            start_menu.DrawMenu(window_);
        }
        else if (level_menu.IsOpen())
        {
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (mouse_position.x >= 57 && mouse_position.x <= 240 && mouse_position.y >= 822 && mouse_position.y <= 877)
                {
                    start_menu.Open();
                    level_menu.Close();
                }
                else if (mouse_position.x >= 1204 && mouse_position.x <= 1472 && mouse_position.y >= 221 && mouse_position.y <= 277)
                {
                    LoadLevel("src/levels/level1.txt");
                    lose_menu.Close();
                    win_menu.Close();
                    level_menu.Close();
                }
                else if (mouse_position.x >= 1204 && mouse_position.x <= 1472 && mouse_position.y >= 420 && mouse_position.y <= 479)
                {
                    LoadLevel("src/levels/level2.txt");
                    lose_menu.Close();
                    win_menu.Close();
                    level_menu.Close();
                }
                else if (mouse_position.x >= 1204 && mouse_position.x <= 1472 && mouse_position.y >= 624 && mouse_position.y <= 680)
                {
                    LoadLevel("src/levels/level3.txt");
                    lose_menu.Close();
                    win_menu.Close();
                    level_menu.Close();
                }
            }
            level_menu.DrawMenu(window_);
        }
        else if (lose_menu.IsOpen())
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                
                if (mouse_position.x >= 56 && mouse_position.x <= 304 && mouse_position.y >= 219 && mouse_position.y <= 283)
                {
                    LoadLevel(current_level_file_name_);
                    lose_menu.Close();
                    win_menu.Close();
                    level_menu.Close();
                } 
                else if (mouse_position.x >= 57 && mouse_position.x <= 440 && mouse_position.y >= 222 && mouse_position.y <= 677)
                {
                    start_menu.Open();
                    lose_menu.Close();
                    win_menu.Close();
                }
            }
            game_view = window_.getDefaultView();
            window_.setView(game_view);
            lose_menu.DrawMenu(window_); 
        }
        else if (win_menu.IsOpen())
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (mouse_position.x >= 56 && mouse_position.x <= 304 && mouse_position.y >= 219 && mouse_position.y <= 283)
                {
                        if (current_level_file_name_=="src/levels/level1.txt")
                        {
                            LoadLevel("src/levels/level2.txt");
                            lose_menu.Close();
                            win_menu.Close();
                            level_menu.Close();
                        }
                        else if (current_level_file_name_=="src/levels/level2.txt")
                        {
                            LoadLevel("src/levels/level3.txt");
                            lose_menu.Close();
                            win_menu.Close();
                            level_menu.Close();
                        }else if (current_level_file_name_=="src/levels/level3.txt")
                        {
                            LoadLevel("src/levels/level1.txt");
                            lose_menu.Close();
                            win_menu.Close();
                            level_menu.Close();
                        }
                }
                else if (mouse_position.x >= 57 && mouse_position.x <= 440 && mouse_position.y >= 422 && mouse_position.y <= 677)
                {
                    start_menu.Open();
                    lose_menu.Close();
                    win_menu.Close();
                }
            }
            game_view = window_.getDefaultView();
            window_.setView(game_view);
            win_menu.DrawMenu(window_); 
        } 
        else
        {
            window_.setView(game_view);
            current_level_.GetBird()->Step();
            sf::Vector2f bird_position = sf::Vector2f(100 * current_level_.GetBird()->GetBody()->GetPosition().x, 900 - (100 * current_level_.GetBird()->GetBody()->GetPosition().y));
            sf::Vector2f default_center = window_.getDefaultView().getCenter();
            if (!stable)
            {
                game_view.setCenter(std::min(std::max(bird_position.x, window_.getDefaultView().getCenter().x), 1600 * 1.f), std::min(bird_position.y, default_center.y));
            }
            current_level_.GetWorld()->Step(1.0f /60, 6, 2);
            bool prev_stable = stable;

            stable = !current_level_.RenderLevel(window_);
            is_stable = stable && !prev_stable;

            sf::Vector2f mouse_position = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));
            sf::Vector2f slingshot_center = sf::Vector2f(300,650);
            sf::Vector2f difference = mouse_position - slingshot_center;
            if (difference.x < 0)
            {
                if (difference.y > 0)
                {
                    angle = 90 + atan(difference.x / difference.y)* (180.0f / M_PI);
                }
                else if (difference.y == 0)
                {
                    angle = 0;
                }
                else
                {
                    angle = 270 + atan(difference.x / difference.y)* (180.0f / M_PI);
                }
                power = std::min(sqrt(pow(difference.x, 2.0f) + pow(difference.y, 2.0f)), 100.0f);
            }
            else
            {
                angle = 0;
                power = 0 ;
            }
            bool bird_has_been_thrown = current_level_.GetBird()->IsThrown();
            if (is_stable && bird_has_been_thrown && current_level_.GetBird())
            {
                current_level_.SetBird();
                bird_position = sf::Vector2f(100 * current_level_.GetBird()->GetBody()->GetPosition().x, 900 - (100 * current_level_.GetBird()->GetBody()->GetPosition().y));
                game_view.setCenter(std::max(bird_position.x, window_.getDefaultView().getCenter().x), std::min(bird_position.y, default_center.y));
            }
            score.setPosition(window_.mapPixelToCoords(sf::Vector2i(static_cast<int>(window_.getSize().x * 0.7), 0)));
            score.setString(std::string("Score: ") + std::to_string(current_level_.GetScore()));
            window_.draw(score);
            if (current_level_.IsLevelEnded() && stable)
            {
                if (!current_level_.IsLevelWin())
                {
                    lose_menu.Open();
                }
                else
                {
                    win_menu.Open();
                }
            }
        }
        window_.display();  
    }
    
}
        
            
