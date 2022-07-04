#include "helpers.h"

// Let user pick a side, X or O
void setPlayer(sf::RenderWindow &window, sf::Font font, sf::Event &event, std::string &playerH, std::string &playerAI, bool &chosenPlayer)
{
    sf::RectangleShape rectangle(sf::Vector2f(600.f, 300.f));
    rectangle.setFillColor(sf::Color(0,0,0));
    rectangle.setOutlineThickness(15.f);
    rectangle.setPosition(sf::Vector2f(150, 300));

    sf::Text text("Choose player:", font, 60);
    sf::Text textX("X", font, 100);
    sf::Text textO("O", font, 100);
    text.setPosition(sf::Vector2f(270, 350));
    textX.setPosition(sf::Vector2f(320, 440));
    textO.setPosition(sf::Vector2f(530, 440));
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
            // User clicked on X
            playerH = X;
            playerAI = O;
            sf::sleep(sf::Time(sf::seconds(0.3)));
            window.clear();
            chosenPlayer = true;
        }
        if (textO.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
        {
            // User clicked on O
            playerH = O;
            playerAI = X;
            sf::sleep(sf::Time(sf::seconds(0.3)));
            window.clear();
            chosenPlayer = true;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        // User pressed X
        playerH = X;
        playerAI = O;
        sf::sleep(sf::Time(sf::seconds(0.3)));
        window.clear();
        chosenPlayer = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    {
        // User pressed O
        playerH = O;
        playerAI = X;
        sf::sleep(sf::Time(sf::seconds(0.3)));
        window.clear();
        chosenPlayer = true;
    }

}

// Draw the horizontal and vertical lines of the TTT board
void drawBoard(sf::RenderWindow &window) 
{
    sf::RectangleShape hline1(sf::Vector2f(900, 10)); // Horizontal
    hline1.move(sf::Vector2f(0, 300));
    sf::RectangleShape hline2(sf::Vector2f(900, 10)); // Horizontal
    hline2.move(sf::Vector2f(0, 600));

    //sf::Angle a1  = sf::degrees(90);
    //sf::Angle a1 = std::literals::90_deg;
    sf::RectangleShape vline1(sf::Vector2f(900, 10)); // Vertical
    vline1.move(sf::Vector2f(300, 0));
    vline1.rotate(90);
    sf::RectangleShape vline2(sf::Vector2f(900, 10)); // Vertical
    vline2.move(sf::Vector2f(600, 0));
    //vline2.setRotation(a1);
    vline2.rotate(90);

    window.draw(hline1);
    window.draw(hline2);
    window.draw(vline1);
    window.draw(vline2);
}

// Convert mouse click to integer
// The integer is used in the moveConverter function in ttt.h
// In turn, moveConverter converts the integer to a Point which is then used to keep track of the moves
int convertClick(sf::Vector2i v)
{
    int x = v.x;
    int y = v.y;

    if (x >= 0 && v.x < 300 && y >= 0 && y < 300) { // TOP ROW LEFT CELL
        return 1;
    }
    if (x >= 300 && x < 600 && y >= 0 && y < 300) { // TOP ROW MIDDLE CELL
        return 2;
    }
    if (x >= 600 && x < 900 && y >= 0 && y < 300) { // TOP ROW RIGHT CELL
        return 3;
    }
    if (x >= 0 && x < 300 && y >= 300 && y < 600) { // MIDDLE ROW LEFT CELL
        return 4;
    }
    if (x >= 300 && x < 600 && y >= 300 && y < 600) { // MIDDLE ROW MIDDLE CELL
        return 5; 
    }
    if (x >= 600 && x < 900 && y >= 300 && y < 600) { // MIDDLE ROW RIGHT CELL
        return 6;
    }
    if (x >= 0 && x < 300 && y >= 600 && y < 900) { // BOTTOM ROW LEFT CELL
        return 7;
    }
    if (x >= 300 && x < 600 && y >= 600 && y < 900) { // BOTTOM ROW MIDDLE CELL
        return 8;
    }
    if (x >= 600 && x < 900 && y >= 600 && y < 900) { // BOTTOM ROW RIGHT CELL
        return 9;
    }

    throw std::invalid_argument("Invalid mouse coordinates");
}

// Convert move to a position on the window
// These x and y coordinates are used to draw the text (X/O) on the window at the right place
sf::Vector2f MoveToPos(Point* p)
{
    sf::Vector2f v;

    if (p->x == 0 && p->y == 0) {            ///////// COORDINATES WINDOW ////////
        v.x = 90;                           // | 60,30  | 260,30  | 460, 30  | //
        v.y = 50;                           // | 60,230 | 260,230 | 460, 230 | //                                       
    }                                        // | 60,430 | 260,430 | 460, 430 | //
    if (p->x == 1 && p->y == 0) {            /////////////////////////////////////
        v.x = 90;
        v.y = 350;
    }
    if (p->x == 2 && p->y == 0) {
        v.x = 90;
        v.y = 650;
    }
    if (p->x == 0 && p->y == 1) {
        v.x = 390;
        v.y = 50;
    }
    if (p->x == 1 && p->y == 1) {
        v.x = 390;
        v.y = 350;
    }
    if (p->x == 2 && p->y == 1) {
        v.x = 390;
        v.y = 650;
    }
    if (p->x == 0 && p->y == 2) {
        v.x = 690;
        v.y = 50;
    }
    if (p->x == 1 && p->y == 2) {
        v.x = 690;
        v.y = 350;
    }
    if (p->x == 2 && p->y == 2) {
        v.x = 690;
        v.y = 650;
    }

    return v;
}

// Display winner and ask user to play again
void displayEnding(sf::RenderWindow &window, std::string winMsg, std::vector<std::vector< std::string > > &board, bool &chosenplayer, sf::Font font, sf::Event &event, std::vector<sf::Text> &v, bool &gameover)
{
    sf::RectangleShape rectangle(sf::Vector2f(600.f, 300.f));
    rectangle.setFillColor(sf::Color(0,0,0));
    rectangle.setOutlineThickness(15.f);
    rectangle.setPosition(sf::Vector2f(150, 300));

    sf::Text text(winMsg + " Play again?", font, 60);
    sf::Text text1("Press [y] or [n]", font, 60);
    if (winMsg == "AI won!")
    {
        text.setPosition(sf::Vector2f(210, 360));
    }
    else
    {
        text.setPosition(sf::Vector2f(190, 360));
    }
    text1.setPosition(sf::Vector2f(270, 450));
    text.setStyle(sf::Text::Bold);

    window.draw(rectangle);
    window.draw(text);
    window.draw(text1);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
    {
        // Set variables back to initial state if user wants to play again
        v.clear();  
        window.clear();
        board = initialState();
        chosenplayer = false;
        gameover = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) 
    {       
        // Close the window if user wants to stop playing
        window.close();
    }  
}