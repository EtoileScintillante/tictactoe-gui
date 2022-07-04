/*                                  
 * helpers.h
 *
 * Created on: 3 July 2022
 * Author: EtoileScintillante
 */

#ifndef __HELPERS__
#define __HELPERS__

#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <SFML/System.hpp>
#include <string>
#include "ttt.h"

/**
 * Let the user pick a side, X or O.
 * 
 * @param[out] window window that will be rendered
 * @param font font which will be used to style the text
 * @param[out] event event to which the computer listens (in this case mouse and keyboard)
 * @param[out] playerh human player
 * @param[out] playerAI AI player
 * @param[out] chosenPlayer true if human has picked a side, false otherwise
 */
void setPlayer(sf::RenderWindow &window, sf::Font font, sf::Event &event, std::string &playerH, std::string &playerAI, bool &chosenPlayer);

/**
 * Draw the vertical and horizontal lines of the of the Tic Tac Toe board.
 * The lines will be drawn in white.
 * Assumption: window size is 600 x 600
 * 
 * @param[out] window window on which the lines will be drawn
 */
void drawBoard(sf::RenderWindow &window);

/**
 * Convert mouseclick to the corresponding number,
 * depending on which cell the user clicked.
 * Tic Tac Toe (TTT) has 9 cells and therefore the number can be anywhere between 1 and 9.
 * To keep track of the score, the program represents the TTT board as a 2d vector.
 * The number obtained by this function will be used to determine in which row and column the X (or O)
 * needs to be inserted (see moveConvert in ttt.h).
 * 
 * @param v Vector2i which holds the coordinates of the mouseclick
 * @return integer representing the cell on which the user clicked 
 */
int convertClick(sf::Vector2i v);
  
/**
 * Convert row and column to the corresponding coordinates on the window.
 * This function is used to determine where to draw the Xs and Os. 
 * 
 * @param p Pointer to Point which holds the row and column number of the player's move in the 2d vector of the board.
 * @return Vector2f holding the x and y coordinates of where the X (or O) should be drawn.
 */
sf::Vector2f MoveToPos(Point* p);

/**
 * Display the winner and ask user to play again or not.
 * In case the user wants to play again, some boolean variables will be reset.
 * In addition, the 2d vector representing the TTT baord and the vector holding 
 * the drawings of the Xs and Os board will both be cleared.
 * 
 * @param[out] window window that will be rendered.
 * @param winMsg message telling who won.
 * @param[out] board 2d vector representing the TTT board.
 * @param[out] chosenPlayer boolean value (true if user has picked a side, false otherwise).
 * @param font font in which the text will be styled.
 * @param[out] event event to which the computer listens (in this case keyboard).
 * @param[out] v vector which holds the drawings of the Xs and Os.
 * @param[out] gameover boolean value (true if game is over, false otherwhise).
 */
void displayEnding(sf::RenderWindow &window, std::string winMsg, std::vector<std::vector< std::string > > &board, bool &chosenplayer, sf::Font font, sf::Event &event, std::vector<sf::Text> &v, bool &gameover);

#endif /*__HELPERS__*/





