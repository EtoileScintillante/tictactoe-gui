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

/**
 * Initialize an empty Tic Tac Toe board.
 * 
 * @return 2d vector of strings filled with value EMPTY.
 */
std::vector<std::vector<std::string> > initialState();

/**
 * Get the empty cell count.
 * 
 * @param board 2d vector of strings representing the TTT board.
 * @return empty cell count.
 */
int emptyCells(std::vector<std::vector<std::string> > board);


/**
 * Determine whose turn it is.
 * Rule of this program: X always starts. 
 * 
 * @param board 2d vector of strings representing the TTT board
 * @return player whose turn it is.
 */
std::string player(std::vector<std::vector<std::string> > board);

/**
 * Get all the available moves. 
 * 
 * @param board 2d vector of strings representing the TTT board.
 * @return vector of pointers to Points which represents the available moves.
 */
std::vector<Point*> availableActions(std::vector<std::vector<std::string> > board);

/**
 * Returns the TTT board that results from making move (x, y). 
 * 
 * @param board 2d vector of strings representing the TTT board.
 * @param action pointer to Point representing the made move.
 * @return 2d vector of strings representing the TTT board after performing the action.
 */
std::vector<std::vector<std::string> > result(std::vector<std::vector<std::string> > board, Point* action);

/**
 * Free memory allocated on the heap.
 * This function is called in minimax() to free the memory allocated
 * by availableActions().
 * 
 * @param v vector of pointers.
 * @see minimax
 */
void deleteVect(std::vector<Point*> v);

/**
 * Returns the winner of the game if there is one. 
 * 
 * @param board 2d vector of strings representing the TTT board.
 * @return winner of the game. If it's a tie, it returns "no winner".
 */
std::string winner (std::vector<std::vector< std::string > > board);

/**
 * Determine whether the TTT board is a terminal state,
 * meaning the game is over. 
 * 
 * @param board 2d vector of strings representing the TTT board.
 * @return true if the game is over, false otherwise.
 */
bool terminal(std::vector<std::vector<std::string > > board);

/**
 * Determine the utility of the TTT board.
 * This function is used by minimax() to get the optimal move. 
 * 
 * @see minimax
 * @param board 2d vector of strings representing the TTT board.
 * @return 1 if X has won, -1 if O has won, 0 otherwhise.
 */
int utility(std::vector<std::vector<std::string > > board);

/**
 * Get the optimal move for the current player.
 * O is minimizing player and X the maximizing player. 
 * 
 * @param board 2d vector of strings representing the TTT board.
 * @return Point representing the optimal move.
 */
Point minimax(std::vector<std::vector<std::string > > board);

/**
 * Function called by minimax() to determine the optimal move.
 * 
 * @see minimax
 * @param board 2d vector of strings representing the TTT board.
 * @return utility of the TTT board.
 */
int lowestValue(std::vector<std::vector<std::string > > board);

/**
 * Function called by minimax() to determine the optimal move.
 * 
 * @see minimax
 * @param board 2d vector of strings representing the TTT board.
 * @return utility of the TTT board.
 */
int highestValue(std::vector<std::vector<std::string > > board);

/**
 * Print the TTT board.
 * 
 * @param board 2d vector of strings representing the TTT board.
 */
void printBoard(std::vector<std::vector<std::string> > board);

/**
 * Convert cell number (1-9) to row and column.
 * This is convertion is needed to keep track of all the moves 
 * in the 2d vector of strings representing the TTT board.
 * See point.h for a better explanation.
 * 
 * @param i cell number.
 * @return Point corresponding to the cell number.
 */
Point moveConverter(int i);

#endif /*__TTT_FUNCTIONS__*/