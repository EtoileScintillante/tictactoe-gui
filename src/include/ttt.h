/*                                  
 * ttt.h
 *
 * Created on: 3 July 2022
 * Author: EtoileScintillante
 */

#ifndef __TTT_FUNCTIONS__
#define __TTT_FUNCTIONS__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <limits>
#include <random>
#include "point.h"

const std::string EMPTY = "empty";
const std::string X = "X";
const std::string O = "O";
const int ROW = 3;  // 3 x 3 board
const int COL = 3;

//TODO: FINISH DOCUMENTATION!

// Returns vector with initial state of board (all empty cells)
std::vector<std::vector<std::string> > initialState();

// Return empty cell count
int emptyCells(std::vector<std::vector<std::string> > board);

// Return X or O, depending on whose turn it is
std::string player(std::vector<std::vector<std::string> > board);

// Return vector with available moves
std::vector<Point*> availableActions(std::vector<std::vector<std::string> > board);

// Returns the board that results from making move (i, j)
std::vector<std::vector<std::string> > result(std::vector<std::vector<std::string> > board, Point* action);

// Deallocate memory 
void deleteVect(std::vector<Point*> v);

// Return winner of the game, if there is one
std::string winner (std::vector<std::vector< std::string > > board);

// Returns true if the game is over, false otherwise
bool terminal(std::vector<std::vector<std::string > > board);

// Return 1 if X has won, -1 if O has won, 0 otherwhise
// X is maximizing player, O is minimizing player
int utility(std::vector<std::vector<std::string > > board);

// Return the optimal action for the current player on the board
Point minimax(std::vector<std::vector<std::string > > board);

// Function called by minimax() to determine optimal move
int lowestValue(std::vector<std::vector<std::string > > board);

// Function called by minimax() to determine optimal move
int highestValue(std::vector<std::vector<std::string > > board);

// Prints the board
void printBoard(std::vector<std::vector<std::string> > board);

// Convert cell number to coordinates on board
// These coordinates are used to update the board (which is a 2d vector)
// To actually draw a move on the window, different coordinates are used (see MoveToPos in helpers.h)
Point moveConverter(int i);

#endif /*__TTT_FUNCTIONS__*/