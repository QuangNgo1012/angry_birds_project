#include "menu_level.hpp"

LevelMenu::LevelMenu() : Menu()
{
    std::string items_texts[items_number] = {"Level 1","Level 2","Level 3","Back"};
    items[0].setFont(font);
    items[0].setString(items_texts[0]);
    items[0].setFillColor(sf::Color::White);
    items[0].setCharacterSize(80);
    items[0].setPosition(1200, 200);

    items[1].setFont(font);
    items[1].setString(items_texts[1]);
    items[1].setFillColor(sf::Color::White);
    items[1].setCharacterSize(80);
    items[1].setPosition(1200, 400);

    items[2].setFont(font);
    items[2].setString(items_texts[2]);
    items[2].setFillColor(sf::Color::White);
    items[2].setCharacterSize(80);
    items[2].setPosition(1200, 600);

    items[3].setFont(font);
    items[3].setString(items_texts[3]);
    items[3].setFillColor(sf::Color::White);
    items[3].setCharacterSize(80);
    items[3].setPosition(50, 800);
    
};

void LevelMenu::DrawMenu(sf::RenderWindow &window)
{
    window.draw(background);
    for (auto item : items)
    {
        window.draw(item);
    }
}