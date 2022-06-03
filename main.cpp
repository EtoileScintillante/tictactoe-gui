#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <SFML/System.hpp>
#include "headers/ttt.h"

void setPlayer(sf::RenderWindow &window, sf::Font font, sf::Event &event, string &playerH, string &playerAI, bool &chosenPlayer);
void drawBoard(sf::RenderWindow &window);
int convertClick(sf::Vector2i v);
void drawMove(Point* p);
void displayEnding(sf::RenderWindow &window, string winner, vector<vector< string > > &board, bool &chosenPlayer, sf::Font font, sf::Event &event);

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
            setPlayer(window, font, event, playerH, playerAI, chosenPlayer);
        }

        // Draw board of user has chosen a player
        else {
            drawBoard(window);
        }

        window.display();
    }

    return 0;
}

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
int convertClick(sf::Vector2i v)
{
    //TODO
}

// Convert move to drawing on the window
void drawMove(Point* p)
{
    //TODO
}

// Display winner and ask user to play again
void displayEnding(sf::RenderWindow &window, string winner, vector<vector< string > > &board, bool &chosenPlayer, sf::Font font, sf::Event &event)
{
    //TODO
}