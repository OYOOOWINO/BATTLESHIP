#include "battle.h"

/**
 * Function name : printGameBoard ()
 * Usage         : printGameBoard (Cell **gameBoard, bool); 
 * Definition    : prints the game board on the console
 *                 screen can optionally show or not showing craft a grid co-ordinates
 *Return: none
 */
void printPopulatedBoard(Cell **gameBoard, bool showCraft)
{
    int i = 0, j = 0;
    /**column labels**/
    printf("    0  1  2  3  4  5  6  7  8  9\n");
    /**char array for elements row labels **/
    char rowLabel[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    /**Print out 2D array elements**/
    for (i = 0; i < ROWS; i++)
    {
        printf(" %c ", rowLabel[i]);

        for (j = 0; j < COLS; j++)
        {
            /**showCraft in coordinates**/
            if (showCraft == true)
                printf(" %c ", gameBoard[i][j].symbol);
            else
            {
                switch (gameBoard[i][j].symbol)
                {
                case HIT:
                    printf(" %c ", HIT);
                    break;
                case MISS:
                    printf(" %c ", MISS);
                    break;
                case WATER:
                default:
                    printf(" %c ", WATER);
                    break;
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}
