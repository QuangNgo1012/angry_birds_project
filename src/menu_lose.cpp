#include "menu_lose.hpp"

LoseMenu::LoseMenu() : Menu()
{
    std::string items_texts[items_number] = {"Replay","Main Menu","You Lose!"};
    items[0].setFont(font);
    items[0].setString(items_texts[0]);
    items[0].setFillColor(sf::Color::White);
    items[0].setCharacterSize(80);
    items[0].setPosition(50, 200);

    items[1].setFont(font);
    items[1].setString(items_texts[1]);
    items[1].setFillColor(sf::Color::White);
    items[1].setCharacterSize(80);
    items[1].setPosition(50, 600);

    items[2].setFont(font);
    items[2].setString(items_texts[2]);
    items[2].setFillColor(sf::Color::Red);
    items[2].setCharacterSize(150);
    items[2].setPosition(460, 50);
    
};

void LoseMenu::DrawMenu(sf::RenderWindow &window)
{
    window.draw(background);
    for (auto item : items)
    {
        window.draw(item);
    }
}