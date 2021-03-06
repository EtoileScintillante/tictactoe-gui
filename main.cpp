/* Play Tic Tac Toe against an AI */

#include "helpers.h"

int main()
{   
    // Create window
    auto window = sf::RenderWindow{ { 600u, 600u }, "Tic Tac Toe" };

    // Initialize empty board and players
    std::vector<std::vector< std::string > > b = initialState();
    std::string playerH, playerAI;
    bool chosenPlayer = false;
    bool gameOVER = false;
    int moveCount = 0;

    /* Create 'lag' so that when the AI makes the first move
    it does not draw the board and move at the same time (that looks ugly) */
    int lag = 0;

    // Initialize vector to store text drawings
    std::vector<sf::Text> vt;

    // Load font
    sf::Font font;
    if (!font.loadFromFile("resources/tuffy.ttf"))
    {
        std::cout << "Font could not be loaded from file" << std::endl;
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

        // Let human choose player 
        if (chosenPlayer == false) {
            setPlayer(window, font, event, playerH, playerAI, chosenPlayer);
            sf::sleep(sf::Time(sf::seconds(0.3)));
        }

        // Draw board if human has chosen a player
        else {
            window.clear();

            if (gameOVER == false) {

                // Increment lag
                lag++;

                // Draw board
                drawBoard(window);

                // Get the current player
                std::string currPlayer = player(b);

                // Display message saying X always begins so that human knows they can or cannot make the first move 
                if (lag < 2000) { 
                    sf::Text text("Player X starts!", font, 18);
                    text.setFillColor(sf::Color::Yellow);
                    text.setStyle(sf::Text::Bold);
                    text.setPosition(sf::Vector2f(230, 30));
                    window.draw(text);
                }
                
                // User makes move
                if (currPlayer == playerH) {

                    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                        int cell = convertClick(sf::Mouse::getPosition(window)); // Convert click to cell number
                        Point move = moveConverter(cell); // Convert cell number to row and column on the board (the 2d vector)
                        moveCount++;
                        sf::Text t(playerH, font, 120);
                        t.setPosition(MoveToPos(&move)); // Convert row and column to coordinates on the window
                        vt.push_back(t); // Store drawing of move (X or O) in vector
                        b = result(b, &move); // Update board
                    }
                }

                // AI makes move
                else {
                    // Add sleep time otherwise it goes too fast
                    sf::sleep(sf::Time(sf::seconds(0.5)));
                    Point move = minimax(b);
                    b = result(b, &move); // Update board
                    moveCount++;
                    sf::Text t(playerAI, font, 120);
                    t.setPosition(MoveToPos(&move)); // Convert row and column of move to coordinates of on the window
                    vt.push_back(t); // Store drawing of move (X or O) in vector
                }

                // Draw the moves
                if (lag > 1800 && moveCount >= 1) {
                    for (int i = 0; i < vt.size(); i++) {
                    window.draw(vt[i]);
                    }
                }
            }
            
            // Display message when game is finished
            if (terminal(b) == true) {

                if (gameOVER == false) {
                    /* Show end result to user for a split second
                    before clearing everything */
                    window.display();
                    sf::sleep(sf::Time(sf::seconds(0.5)));
                    lag = 0; // Lag back to zero
                    moveCount = 0; // Count back to zero
                    gameOVER = true;
                }

                else {
                    if (winner(b) == playerH) {
                        displayEnding(window, "Human won!", b, chosenPlayer, font, event, vt, gameOVER);
                    }
                    if (winner(b) == playerAI) {
                        displayEnding(window, "AI won!", b, chosenPlayer, font, event, vt, gameOVER);
                    }
                    if (winner(b) == "no winner") {
                        displayEnding(window, "It's a tie!", b, chosenPlayer, font, event, vt, gameOVER);
                    }
                }
            }
        }
       window.display();
    }
    return 0;
}


