/*                                  
 * point.h
 *
 * Created on: 3 July 2022
 * Author: EtoileScintillante
 *
 * This class is used to keep track of all the moves made by the human and AI player. 
 * The moves are stored in a 2d vector of strings ("X", "O" or "empty"). 
 * A Tic Tac Toe board consists of 3 rows and 3 columns. 
 * The attributes X and Y represent the row and column, respectively.
 * For example, a move made by player X in the top left cell will have Point(0, 0)
 * and in the vector the move will be inserted as board[0][0] = "X".
 */

#ifndef __POINT__
#define __POINT__

class Point {
public:
    int x;
    int y;
    Point(int X, int Y);
    void print() 
    {
        printf("(%i, %i)\n", x, y);
    }
};

Point::Point(int X, int Y)
{
    x = X;
    y = Y;
}

#endif /*__POINT__*/