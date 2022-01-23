#include "battle.h"
/**
 * Usage         : updateGameBoard (Cell **gameBoard, gridBox target);
 * Definition    : Function updates the game board whether 
 *                 its a hit or miss
 * Return: none
 */

void updateGameBoard(Cell **gameBoard, gridBox target)
{
    /*I*Check the character at the target location to deter if a HIT or A MISS**/
    switch (gameBoard[target.row][target.column].symbol)
    {
    /* miss */
    case WATER:
        gameBoard[target.row][target.column].symbol = MISS;
        break;

    /* hit */
    case CARRIER:
    case BATTLESHIP:
    case CRUISER:
    case SUBMARINE:
    case DESTROYER:
        gameBoard[target.row][target.column].symbol = HIT;
        break;
    case HIT:
    case MISS:
    default:
        break;
    }
}
