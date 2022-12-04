#include "menu_start.hpp"

StartMenu::StartMenu() : Menu()
{
    std::string items_texts[items_number] = {"Start","Quit"};
    items[0].setFont(font);
    items[0].setString(items_texts[0]);
    items[0].setFillColor(sf::Color::White);
    items[0].setCharacterSize(80);
    items[0].setPosition(50, 200);

    items[1].setFont(font);
    items[1].setString(items_texts[1]);
    items[1].setFillColor(sf::Color::White);
    items[1].setCharacterSize(80);
    items[1].setPosition(50, 400);
    
};

void StartMenu::DrawMenu(sf::RenderWindow &window)
{
    window.draw(background);
    for (auto item : items)
    {
        window.draw(item);
    }
}
