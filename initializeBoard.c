#include "battle.h"

/**
 * Function name : initializeBoard ()
 * Usage         : initializeGameBoard ();
 * Definition    : initializes values of the multi-
 *                 dimensional array called gameBoard.
 * Return : void
 * Post-condition: Array initialize to (~) tilde representing water 
 */

void initializeBoard(Cell **gameBoard)
{
    int i = 0, j = 0;

    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
        {
            gameBoard[i][j].symbol = WATER;
            gameBoard[i][j].position.row = i;
            gameBoard[i][j].position.column = j;
        }
}
