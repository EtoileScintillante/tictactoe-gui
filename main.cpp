#include <SFML/Graphics.hpp>
#include <stdexcept>
#include "headers/ttt.h"

int main()
{   
    // Create window
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(600, 600)), "Tic Tac Toe");

    // Initialize empty board and players
    vector<vector< string > > b = initialState();
    string playerH, playerAI;
    bool chosenPlayer = false;

    // Load font
    sf::Font font;
    if (!font.loadFromFile("resources/tuffy.ttf"))
    {
        cout << "Font could not be loaded from file" << endl;
        return 1;
    }

    // Creating the lines to draw a 3 x 3 board
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
    
    // Game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Let user choose player 
        if (chosenPlayer == false) {
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
        }
        else {
            window.draw(hline1);
            window.draw(hline2);
            window.draw(vline1);
            window.draw(vline2);
        }

        window.display();
    }

    return 0;
}