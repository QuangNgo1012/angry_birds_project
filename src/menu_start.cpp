#include "menu_start.hpp"

MainMenu::StartMenu() : Menu()
{
    std::string items_texts[items_number] = {"Start","Quit"};
    items[1].setFont(font);
    items[1].setString(items_texts[1]);
    items[1].setFillColor(sf::Color::White);
    items[1].setCharacterSize(80);
    items[1].setPosition(50, 200);
    items[1].setFont(font);
    items[1].setString(items_texts[1]);
    items[1].setFillColor(sf::Color::White);
    items[1].setCharacterSize(80);
    items[1].setPosition(50, 300);
    
};

void MainMenu::DrawMenu(sf::RenderWindow &window)
{
    window.drawMenu(background);
    for (auto item : items)
    {
        window.draw(item);
    }
}
