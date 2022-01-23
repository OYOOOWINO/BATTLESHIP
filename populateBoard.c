#include "battle.h"

/**
 * Function name : getRandomNumber ()
 * Usage         : getRandomNumber(int lowest, int highest); 
 * Definition    : Generates a random integer between lowest and highest specified
 * Return: integer
 */
int getRandomNumber(int lowest, int highest)
{
    if (lowest == 0)
        return rand() % ++highest;

    if (lowest > 0)
        return rand() % ++highest + lowest;
}

/**
 * Function name : positionValid ()
 * Usage         : isValidLocation (Cell**, gridBox, int, int);
 * Definition    : checks if specified position, direction and
 *                 length is valid on the game board
 * Return : bool
 */
bool positionValid(Cell **gameBoard, gridBox position,
                   int direction, int length)
{
    int i = length - 1;
    bool isValid = true;

    for (i = 0; isValid && i < length; i++)
    {
        /**HORIZOTAL**/
        if (direction == HORIZONTAL)
        {
            /*Check if valid char in position*/
            if (gameBoard[position.row][position.column + i].symbol != WATER &&
                (position.column + i) < COLS)
                isValid = false;
        }
        else
        { /* VERTICAL */
            /*Check if valid char in position*/
            if (gameBoard[position.row + i][position.column].symbol != WATER &&
                (position.row + i) < ROWS)
                isValid = false;
        }
    }

    return isValid;
}
/**
 * Function name : generatePosition ()
 * Usage         : generatePosition (int, int);
 * Definition    : generates position depending on the
 *                 direction and length within game board size
 * Return  : gridBox/coo-rdinates
 */
gridBox generatePosition(int direction, int length)
{
    gridBox position;

    if (direction == HORIZONTAL)
    {
        position.row = getRandomNumber(0, ROWS);
        position.column = getRandomNumber(0, COLS - length);
    }
    else
    { /* VERTICAL */
        position.row = getRandomNumber(0, ROWS - length);
        position.column = getRandomNumber(0, COLS);
    }

    return position;
}

/**
 * Function name : placeShip ()
 * Usage         : generatePosition (Cell **, Ship,gridBox , int );
 * Definition    : Inserts a craft charater on the gameboard 
 *                  in a specific direction 
 * Return : void
 * Post-condition: n/a
 */
void placeShip(Cell **gameBoard, Ship ship,
               gridBox position, int direction)
{
    int i = ship.length - 1;
    for (i = 0; i < ship.length; i++)
    {
        if (direction == HORIZONTAL)
            gameBoard[position.row][position.column + i].symbol = ship.symbol;
        else /* VERTICAL */
            gameBoard[position.row + i][position.column].symbol = ship.symbol;
    }
}

/**
 * Function name : populateBoard()
 * Usage         : populateBoard(Cell**, Ship);
 * Definition    : Randomly place ship on the 
 *                 game board
 * Return : void
 */

void populateBoard(Cell **gameBoard, Ship ship[])
{
    gridBox position;
    int direction = -1;
    int i = 0;

    for (i = 0; i < NUM_OF_SHIPS; i++)
    {
        /**Generate positions until a valid one is found then insert ship**/
        while (true)
        {
            direction = getRandomNumber(0, 1); /* 0 -> horizontal, 1 -> vertical */
            position = generatePosition(direction, ship[i].length);

            if (positionValid(gameBoard, position, direction, ship[i].length))
                break;
        }

        /**Insert Ship**/
        placeShip(gameBoard, ship[i], position, direction);
    }
}
