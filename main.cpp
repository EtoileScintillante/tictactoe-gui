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

    // Initialize vector to store users moves
    vector<Point*> p;

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

        // Draw board of user has chosen a player
        else {
            window.clear();
            drawBoard(window);

            string currPlayer = player(b);
            if (currPlayer == playerH) {
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    int cell = convertClick(sf::Mouse::getPosition(window));
                    Point* move = moveConverter(cell);
                    b = result(b, move);
                    p.__emplace_back(move);
                    printBoard(b);
                    sf::sleep(sf::Time(sf::seconds(0.3)));
                }
            }
            else {
                Point move = minimax(b);
                b = result(b, &move);
                p.__emplace_back(&move);
                sf::Vector2f pos = MoveToPos(&move);
            }

            if (terminal(b) == true) {
                cout << "END" << endl;
                freeMemory(p);
                p.clear();
                return 0;
            }
        }

       window.display();
    }
    return 0;
}

