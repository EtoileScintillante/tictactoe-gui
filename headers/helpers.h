#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <SFML/System.hpp>
#include "ttt.h"
#include <string>

// Let the user pick a side, X or O
void setPlayer(sf::RenderWindow &window, sf::Font font, sf::Event &event, string &playerH, string &playerAI, bool &chosenPlayer)
{
    sf::RectangleShape rectangle(sf::Vector2f(400.f, 150.f));
    rectangle.setFillColor(sf::Color(0,0,0));
    rectangle.setOutlineThickness(10.f);
    rectangle.setPosition(sf::Vector2f(100, 200));
    sf::Text text, textX, textO;
    text.setFont(font);
    textX.setFont(font);
    textO.setFont(font);
    text.setString("Choose player:");
    textX.setString("X");
    textO.setString("O");
    text.setCharacterSize(30);
    textX.setCharacterSize(45);
    textO.setCharacterSize(45);
    text.setPosition(sf::Vector2f(200, 220));
    textX.setPosition(sf::Vector2f(200, 280));
    textO.setPosition(sf::Vector2f(370, 280));
    text.setStyle(sf::Text::Bold);
    textX.setStyle(sf::Text::Bold);
    textO.setStyle(sf::Text::Bold);
    window.draw(rectangle);
    window.draw(text);
    window.draw(textX);
    window.draw(textO);
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
    {
        if (textX.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
        {
            playerH = X;
            playerAI = O;
            sf::sleep(sf::Time(sf::seconds(0.5)));
            window.clear();
            chosenPlayer = true;
        }
        if (textO.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
        {
            playerH = O;
            playerAI = X;
            sf::sleep(sf::Time(sf::seconds(0.5)));
            window.clear();
            chosenPlayer = true;
        }
    }
}

// Draw the board (the lines)
void drawBoard(sf::RenderWindow &window) 
{
    sf::RectangleShape hline1(sf::Vector2f(600, 5)); // Horizontal
    hline1.move(sf::Vector2f(0, 200));
    sf::RectangleShape hline2(sf::Vector2f(600, 5)); // Horizontal
    hline2.move(sf::Vector2f(0, 400));
    sf::RectangleShape vline1(sf::Vector2f(600, 5)); // Vertical
    vline1.move(sf::Vector2f(200, 0));
    vline1.rotate(sf::degrees(90));
    sf::RectangleShape vline2(sf::Vector2f(600, 5)); // Vertical
    vline2.move(sf::Vector2f(400, 0));
    vline2.rotate(sf::degrees(90));
    window.draw(hline1);
    window.draw(hline2);
    window.draw(vline1);
    window.draw(vline2);
}

// Convert mouse click to move
// The integer is used in the moveConverter function in ttt.h
int convertClick(sf::Vector2i v)
{
    int x = v.x;
    int y = v.y;

    if (x >= 0 && v.x < 200 && y >= 0 && y < 200) {
        return 1;
    }
    if (x >= 200 && x < 400 && y >= 0 && y < 200) {
        return 2;
    }
    if (x >= 400 && x < 600 && y >= 0 && y < 200) {
        return 3;
    }
    if (x >= 0 && x < 200 && y >= 200 && y < 400) {
        return 4;
    }
    if (x >= 200 && x < 400 && y >= 200 && y < 400) {
        return 5;
    }
    if (x >= 400 && x < 600 && y >= 200 && y < 400) {
        return 6;
    }
    if (x >= 0 && x < 200 && y >= 400 && y < 600) {
        return 7;
    }
    if (x >= 200 && x < 400 && y >= 400 && y < 600) {
        return 8;
    }
    if (x >= 400 && x < 600 && y >= 400 && y < 600) {
        return 9;
    }

    throw invalid_argument("Invalid mouse coordinates");
}

// Convert move to a position on the board
// These x and y coordinates are used to draw the X or O
sf::Vector2f MoveToPos(Point* p)
{
    sf::Vector2f v;

    if (p->x == 0 && p->y == 0) {
        v.x = 60;
        v.y = 30;
    }
    if (p->x == 1 && p->y == 0) {
        v.x = 60;
        v.y = 230;
    }
    if (p->x == 2 && p->y == 0) {
        v.x = 60;
        v.y = 430;
    }
    if (p->x == 0 && p->y == 1) {
        v.x = 260;
        v.y = 30;
    }
    if (p->x == 1 && p->y == 1) {
        v.x = 260;
        v.y = 230;
    }
    if (p->x == 2 && p->y == 1) {
        v.x = 260;
        v.y = 430;
    }
    if (p->x == 0 && p->y == 2) {
        v.x = 460;
        v.y = 30;
    }
    if (p->x == 1 && p->y == 2) {
        v.x = 460;
        v.y = 230;
    }
    if (p->x == 2 && p->y == 2) {
        v.x = 460;
        v.y = 430;
    }

    return v;
}

// Display winner and ask user to play again
void displayEnding(sf::RenderWindow &window, string winner, vector<vector< string > > &board, bool &chosenPlayer, sf::Font font, sf::Event &event, vector<sf::Text> &v, bool &gameover)
{
    sf::RectangleShape rectangle(sf::Vector2f(400.f, 150.f));
    rectangle.setFillColor(sf::Color(0,0,0));
    rectangle.setOutlineThickness(10.f);
    rectangle.setPosition(sf::Vector2f(100, 200));
    sf::Text text, text1;
    text.setFont(font);
    text1.setFont(font);
    text.setString(winner + " Play again?");
    text1.setString("Press [y] or [n]");
    text.setCharacterSize(30);
    text1.setCharacterSize(30);
    text.setPosition(sf::Vector2f(180, 220));
    text1.setPosition(sf::Vector2f(210, 280));
    text.setStyle(sf::Text::Bold);
    window.draw(rectangle);
    window.draw(text);
    window.draw(text1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
    {
        v.clear();
        window.clear();
        board = initialState();
        chosenPlayer = false;
        gameover = false;
        sf::sleep(sf::Time(sf::seconds(0.5)));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) 
    {
            sf::sleep(sf::Time(sf::seconds(0.3)));
            window.close();
    }  
}

