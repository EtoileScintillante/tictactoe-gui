/// THIS FILE CONTAINS FUNCTIONS TO PLAY A GAME OF TIC TAC TOE AGAINS AN AI ///

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <limits>
#include <random>
#include "point.h"
using namespace std;

const string EMPTY = "empty";
const string X = "X";
const string O = "O";
const int ROW = 3;  // 3 x 3 board
const int COL = 3;

int lowestValue(vector<vector<string > > board);
int highestValue(vector<vector<string > > board);

// Returns vector with initial state of board (all empty cells)
vector<vector<string> > initialState() {
    
    vector<string> temp;
    vector<vector<string> > board;

    for (int i = 0; i < ROW; i++) {
        temp.clear();
        for (int j = 0; j < COL; j++) {
            temp.push_back(EMPTY); 
        }
        board.push_back(temp);
    }

    return board;
}

// Return empty cell count
int emptyCells(vector<vector<string> > board) {
    int count = 0;

    for (int i = 0; i < ROW; i++) {

        for (int j = 0; j < COL; j++) {
            if (board[i][j] == EMPTY) {
            count++;
            }
        }
    }

    return count;
}

// Return X or O, depending on whose turn it is
string player(vector<vector<string> > board) {

    if (emptyCells(board) == 0) {
        return "game over";
    }

    // X always begins
    if (emptyCells(board) == 9) {
        return X;
    }
    
    int countX = 0;
    int countO = 0;

    for (int i = 0; i < ROW; i++) {

        for (int j = 0; j < COL; j++) {
            if (board[i][j] == X) {
                countX++;
            }
            if (board[i][j] == O) {
                countO++;
            }
        }
    }

    if (countX > countO) {
        return O;
    }
    else {
        return X;
    }
}

// Return vector with available moves
vector<Point*> availableActions(vector<vector<string> > board) {

    vector<Point*> vect;
    int i = 0;
    int j = 0;

    for (i = 0; i < ROW; i++) {

        for (j = 0; j < COL; j++) {

            if (board[i][j] == EMPTY) {
                Point* p;
                p = new Point();
                p->x = i;
                p->y = j;
                vect.__emplace_back(p);
            }
        }
    }

    return vect;
}

// Returns the board that results from making move (i, j)
vector<vector<string> > result(vector<vector<string> > board, Point* action) {
    
    vector<vector<string> > copyBoard;
    copy(board.begin(), board.end(), back_inserter(copyBoard));

    // Check if action is valid
    if (copyBoard[action->x][action->y] != EMPTY) {
        throw invalid_argument("Invalid move");
    }
    else {
        // Check whose turn it is
        string playerTurn = player(copyBoard);
        copyBoard[action->x][action->y] = playerTurn;
        return copyBoard;
    }
}

// Deallocate memory 
void deleteVect(vector<Point*> v) {

    for (int i = 0; i< v.size();i++) {
        delete (v[i]);
    }
}

// Return winner of the game, if there is one
string winner (vector<vector< string > > board) {

    // Create vector to store all possoible winner options
    vector<vector<string > > winOptions;

    int i;
    // Add horizontal options
    for (int i = 0; i < board.size(); i++) {
        winOptions.push_back(board[i]);
    }

    // Add diogonal option (top left to bottom right)
    vector<string> tlbr;
    for (int i = 0; i < ROW; i++) {
        tlbr.push_back(board[i][i]);
    }
    winOptions.push_back(tlbr);

    // Add diagonal option (top right to bottom left)
    vector<string> trbl;
    for (int i = 0; i < ROW; i++) {
        trbl.push_back(board[i][2 - i]);
    }
    winOptions.push_back(trbl);

    // Add vertical options
    vector<string> vert1;
    vector<string> vert2;
    vector<string> vert3;
    for (int i = 0; i < ROW; i++) {
        vert1.push_back(board[i][0]);
        vert2.push_back(board[i][1]);
        vert3.push_back(board[i][2]);
    }
    winOptions.push_back(vert1);
    winOptions.push_back(vert2);
    winOptions.push_back(vert3);

    // Determine winner
    for (int i = 0; i < winOptions.size(); i++) {
        if (count(winOptions[i].begin(), winOptions[i].end(), X) == 3) {
            return X;
        }
        if (count(winOptions[i].begin(), winOptions[i].end(), O) == 3) {
            return O;
        }
    }

    return "no winner";
}

// Returns true if the game is over, false otherwise
bool terminal(vector<vector<string > > board) {
    
    // If there is a winner, return true
    if (winner(board) != "no winner") {
        return true;
    }

    // If there is no winner and there are no empty cells left, return true
    else {
        if (emptyCells(board) == 0) {
            return true;
        }
        else {
            return false;
        }
    }
}

// Return 1 if X has won, -1 if O has won, 0 otherwhise
// X is maximizing player, O is minimizing player
int utility(vector<vector<string > > board) {

    if (winner(board) == X) {
        return 1;
    }

    else if (winner(board) == O) {
        return -1;
    }

    else if (winner(board) == "no winner" && terminal(board) == true) {
        return 0;
    }
    else {
        throw runtime_error("non-terminal board passed to utility function");
    }
}

// Return the optimal action for the current player on the board
Point minimax(vector<vector<string > > board) {

    // First check if board is not termninal
    if (terminal(board) == true) {
        throw runtime_error("terminal board passed to minimax function");
    }

    // Get the current player
    string currentPlayer = player(board);

    Point optimalMove;
    vector<Point*> v;

    // If board is empty, return random move 
    // Otherwise it takes quite a long time to calculate the first "optimal" move
    if (emptyCells(board) == 9) {

        // Gets 'entropy' from device that generates random numbers itself
        // to seed a mersenne twister (pseudo) random generator
        mt19937 generator(random_device{}());

        v = availableActions(board);

        // Make sure all moves have an equal chance
        uniform_int_distribution<size_t> distribution(0, v.size() - 1);
        size_t number = distribution(generator);
        optimalMove = optimalMove = Point(v[number]->x, v[number]->y);

        // Free memory and return move
        deleteVect(v); 
        v.clear();
        return optimalMove;
    }

    // Maximizing player
    if (currentPlayer == X) {
        int lowest = numeric_limits<int>::min();
        int i;
        v = availableActions(board);
        for (i = 0; i < v.size(); i++) {
            int value = lowestValue(result(board, v[i]));
            if (value > lowest) {
                lowest = value;
                optimalMove = Point(v[i]->x, v[i]->y);
            }
        }
    }

    // Minimizing player
    else {
        int highest = numeric_limits<int>::max();
        int i;
        v = availableActions(board);
        for (i = 0; i < v.size(); i++) {
            int value = highestValue(result(board, v[i]));
            if (value < highest) {
                highest = value;
                optimalMove = Point(v[i]->x, v[i]->y);
            }
        }
    }

    // Free memory and return best move
    deleteVect(v);
    v.clear();
    return optimalMove;
}

// Function called by minimax() to determine optimal move
int lowestValue(vector<vector<string > > board) {

    if (terminal(board) == true) {
        return utility(board);
    }

    else {
        vector<Point*> v = availableActions(board);
        int value = numeric_limits<int>::max();
        int i;
        for (i = 0; i < v.size(); i++) {
            value = min(value, highestValue(result(board, v[i])));
        }
        deleteVect(v);
        v.clear();
        return value;
    }
}

// Function called by minimax() to determine optimal move
int highestValue(vector<vector<string > > board) {
    
    if (terminal(board) == true) {
        return utility(board);
    }

    else {
        vector<Point*> v = availableActions(board);
        int value = numeric_limits<int>::min();
        int i;
        for (i = 0; i < v.size(); i++) {
            value = max(value, lowestValue(result(board, v[i])));
        }
        deleteVect(v);
        v.clear();
        return value;
    }
}

// Prints the board
void printBoard(vector<vector<string> > board) {

    string line = "-------------";
    int x, y;
    vector <string> temp;
    x = 0;
    int counter = 1;

    cout << line << endl;

    for (int i = 0; i < ROW; i++) {

        temp.clear();
        temp = board[x];
        y = 0;

        for (int j = 0; j < COL; j++) {

            if (temp[y] == X || temp[y] == O) {
                printf("|");
                printf("\x1b[32m %s \x1b[0m", (temp[y].c_str()));
            }
            else {
                cout << "| " << counter << " ";
            }
            y++;
            counter++;
        }
        cout << "|\n";
        cout << line << endl;
        x++;
    }
}

// Convert cell number to coordinates on board
// These coordinates are used to update the board (which is a 2d vector)
Point* moveConverter(int i) {

    int a, b;
    switch (i) {             /////// BOARD //////       ///// CELLS OF BOARD ////
        case 1:              //  | 1 | 2 | 3 | //       // | 0,0 | 0,1 | 0,2 | //
            a = 0;           //  | 3 | 5 | 6 | // --->  // | 1,0 | 1,1 | 1,2 | //
            b = 0;           //  | 7 | 8 | 9 | //       // | 2,0 | 2,1 | 2,2 | //
            break;           ////////////////////       /////////////////////////
        case 2:
            a = 0;
            b = 1;
            break;
        case 3:
            a = 0;
            b = 2;
            break;
        case 4:
            a = 1;
            b = 0;
            break;
        case 5:
            a = 1;
            b = 1;
            break;
        case 6:
            a = 1;
            b = 2;
            break;
        case 7:
            a = 2;
            b = 0;
            break;
        case 8:
            a = 2;
            b = 1;
            break;
        case 9:
            a = 2;
            b = 2;
            break;
    }

    Point* p = new Point();
    p->x = a;
    p->y = b;

    return p;
}