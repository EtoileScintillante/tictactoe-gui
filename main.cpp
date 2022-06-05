/* Play Tic Tac Toe against an AI */

#include "headers/helpers.h"

int main()
{   
    // Create window
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(600, 600)), "Tic Tac Toe");

    // Initialize empty board and players
    vector<vector< string > > b = initialState();
    string playerH, playerAI;
    bool chosenPlayer = false;
    bool gameOVER = false;

    // Initialize vector to store text drawings
    vector<sf::Text> vt;

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

        // Let user choose player 
        if (chosenPlayer == false) {
            setPlayer(window, font, event, playerH, playerAI, chosenPlayer);
            sf::sleep(sf::Time(sf::seconds(0.3)));
        }

        // Draw board if user has chosen a player
        else {
            window.clear();

            if (gameOVER == false) {

                /// DRAW BOARD ///
                drawBoard(window);

                string currPlayer = player(b);

                // User makes move
                if (currPlayer == playerH) {

                    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                        int cell = convertClick(sf::Mouse::getPosition(window));
                        Point* move = moveConverter(cell);
                        sf::Text t;
                        t.setCharacterSize(120);
                        t.setString(playerH);
                        t.setFont(font);
                        t.setPosition(MoveToPos(move));
                        vt.push_back(t);
                        b = result(b, move);
                    }
                }

                // AI makes move
                else {
                    // Add sleep time otherwise it goes too fast
                    sf::sleep(sf::Time(sf::seconds(0.5)));
                    Point move = minimax(b);
                    b = result(b, &move);
                    sf::Text t;
                    t.setCharacterSize(120);
                    t.setString(playerAI);
                    t.setFont(font);
                    t.setPosition(MoveToPos(&move));
                    vt.push_back(t);
                }

                /// DRAW ALL THE MADE MOVES ///
                for (int i = 0; i < vt.size(); i++) {
                    window.draw(vt[i]);
                }
            }
            
            // Display message when game is finished
            if (terminal(b) == true) {

                if (gameOVER == false) {
                    // Show end result to user for a split second
                    // before clearing everything
                    window.display();
                    sf::sleep(sf::Time(sf::seconds(1.3)));
                    gameOVER = true;
                }

                else {
                    string winningPlayer = winner(b);
                    if (winningPlayer == playerH) {
                        winningPlayer = "Human won!";
                    }
                    if (winningPlayer == playerAI) {
                        winningPlayer = "AI won!";
                    }
                    if (winningPlayer == "no winner") {
                        winningPlayer = "It's a tie!";
                    }
                    displayEnding(window, winningPlayer, b, chosenPlayer, font, event, vt, gameOVER);
                }
                
            }
        }

       window.display();
    }
    return 0;
}

