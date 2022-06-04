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

            // Check whise turn it is
            if (player(b) == playerH) {
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    int cell = convertClick(sf::Mouse::getPosition(window));
                    Point* playerMove = moveConverter(cell);
                    drawMove(playerMove, b, font, window);
                    b = result(b, playerMove);
                    delete playerMove;
                }
            }
            else {
                Point AImove = minimax(b);
                drawMove(&AImove, b, font, window);
                b = result(b, &AImove);
            }
            if (terminal(b) == true) {
                return 0;
            }
        }

        window.display();
    }

    return 0;
}

