#include "helpers.h"

// Let user pick a side, X or O
void setPlayer(sf::RenderWindow &window, sf::Font font, sf::Event &event, std::string &playerH, std::string &playerAI, bool &chosenPlayer)
{
    sf::RectangleShape rectangle(sf::Vector2f(400.f, 150.f));
    rectangle.setFillColor(sf::Color(0,0,0));
    rectangle.setOutlineThickness(10.f);
    rectangle.setPosition(sf::Vector2f(100, 200));

    sf::Text text("Choose player", font, 30);
    sf::Text textX("X", font, 55);
    sf::Text textO("O", font, 55);
    text.setPosition(sf::Vector2f(200, 220));
    textX.setPosition(sf::Vector2f(215, 270));
    textO.setPosition(sf::Vector2f(345, 270));
    text.setStyle(sf::Text::Bold);
    textX.setStyle(sf::Text::Bold);
    textO.setStyle(sf::Text::Bold);

    window.draw(rectangle);
    window.draw(text);
    window.draw(textX);
    window.draw(textO);

    // If mouse hovers over X, set color to green
    if (textX.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
    {
        textX.setFillColor(sf::Color::Green);
        window.draw(textX);
    }
    // If mouse hovers over O, set color to green
    if (textO.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
    {
        textO.setFillColor(sf::Color::Green);
        window.draw(textO);
    }
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
    sf::RectangleShape hline1(sf::Vector2f(600, 5)); // Horizontal
    hline1.move(sf::Vector2f(0, 200));
    sf::RectangleShape hline2(sf::Vector2f(600, 5)); // Horizontal
    hline2.move(sf::Vector2f(0, 400));

    sf::RectangleShape vline1(sf::Vector2f(600, 5)); // Vertical
    vline1.move(sf::Vector2f(200, 0));
    vline1.rotate(90);
    sf::RectangleShape vline2(sf::Vector2f(600, 5)); // Vertical
    vline2.move(sf::Vector2f(400, 0));
    vline2.rotate(90);

    window.draw(hline1);
    window.draw(hline2);
    window.draw(vline1);
    window.draw(vline2);
}

// Convert mouse click to integer (cell number)
int convertClick(sf::Vector2i v)
{
    int x = v.x;
    int y = v.y;

    if (x >= 0 && v.x < 200 && y >= 0 && y < 200) { // TOP ROW LEFT CELL
        return 1;
    }
    if (x >= 200 && x < 400 && y >= 0 && y < 200) { // TOP ROW MIDDLE CELL
        return 2;
    }
    if (x >= 400 && x < 600 && y >= 0 && y < 200) { // TOP ROW RIGHT CELL
        return 3;
    }
    if (x >= 0 && x < 200 && y >= 200 && y < 400) { // MIDDLE ROW LEFT CELL
        return 4;
    }
    if (x >= 200 && x < 400 && y >= 200 && y < 400) { // MIDDLE ROW MIDDLE CELL
        return 5; 
    }
    if (x >= 400 && x < 600 && y >= 200 && y < 400) { // MIDDLE ROW RIGHT CELL
        return 6;
    }
    if (x >= 0 && x < 200 && y >= 400 && y < 600) { // BOTTOM ROW LEFT CELL
        return 7;
    }
    if (x >= 200 && x < 400 && y >= 400 && y < 600) { // BOTTOM ROW MIDDLE CELL
        return 8;
    }
    if (x >= 400 && x < 600 && y >= 400 && y < 600) { // BOTTOM ROW RIGHT CELL
        return 9;
    }

    throw std::invalid_argument("Invalid mouse coordinates");
}

// Convert move to a position on the window
sf::Vector2f MoveToPos(Point* p)
{
    sf::Vector2f v;

    if (p->x == 0 && p->y == 0) {           ///////// COORDINATES WINDOW ////////
        v.x = 60;                           // | 60,30  | 260,30  | 460, 30  | //
        v.y = 30;                           // | 60,230 | 260,230 | 460, 230 | //                                       
    }                                       // | 60,430 | 260,430 | 460, 430 | //
    if (p->x == 1 && p->y == 0) {           /////////////////////////////////////
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
void displayEnding(sf::RenderWindow &window, std::string winMsg, std::vector<std::vector< std::string > > &board, bool &chosenplayer, sf::Font font, sf::Event &event, std::vector<sf::Text> &v, bool &gameover)
{
    sf::RectangleShape rectangle(sf::Vector2f(400.f, 150.f));
    rectangle.setFillColor(sf::Color(0,0,0));
    rectangle.setOutlineThickness(10.f);
    rectangle.setPosition(sf::Vector2f(100, 200));
    
    sf::Text text(winMsg, font, 35);
    sf::Text text1("Press Y to play again", font, 22);
    sf::Text text2("Press N to quit", font, 22);
    if (winMsg == "AI won!"){
        text.setPosition(sf::Vector2f(235, 210));
        text.setFillColor(sf::Color::Red);
    }
    else if (winMsg == "Human won!") {
        text.setPosition(sf::Vector2f(225, 210));
        text.setFillColor(sf::Color::Green);
    }
    else {
        text.setPosition(sf::Vector2f(225, 210));
        text.setFillColor(sf::Color::Yellow);
    }
    text.setStyle(sf::Text::Bold);
    text1.setPosition(sf::Vector2f(200, 270));
    text2.setPosition(sf::Vector2f(228, 310));

    window.draw(rectangle);
    window.draw(text);
    window.draw(text1);
    window.draw(text2);

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