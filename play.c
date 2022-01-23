#include "battle.h"

/**
 * Function name : getTarget ()
 * Usage         : getTarget ();
 * Definition    : function that prompts user for
 *                 target coordinates and maps to grid on gameBoard 
 * Return : gridBox
 */
gridBox getTarget()
{
    gridBox target;

    // flush buffer stream chars
    fflush(stdin);

    // prompt user for target location
    printf("> Enter Target Co0rdinates(Format> A4):\n");
    printf("> ");
    char row = '\0';
    scanf("%c%d", &row, &target.column);
    /****/

    // match row character to grid
    switch (row)
    {
    case 'A':
        target.row = 0;
        break;

    case 'B':
        target.row = 1;
        break;
    case 'C':
        target.row = 2;
        break;
    case 'D':
        target.row = 3;
        break;
    case 'E':
        target.row = 4;
        break;
    case 'F':
        target.row = 5;
        break;
    case 'G':
        target.row = 6;
        break;
    case 'H':
        target.row = 7;
        break;
    case 'I':
        target.row = 8;
        break;

    default:
        target.row = 9;
        break;
    }
    return target;
}

/**
 * Function name : checkShot()
 * Usage         : getTarget (Cell **, gridBox);
 * Definition    : function that  given user target coordinates 
 *                 and checks if hit or miss 
 * Return : short: whether hit, miss or invalid
 */
short checkShot(Cell **gameBoard, gridBox target)
{
    int hit = -2;

    switch (gameBoard[target.row][target.column].symbol)
    {
    /* miss */
    case WATER:
        hit = 0;
        break;

    /* hit */
    case CARRIER:
    case BATTLESHIP:
    case CRUISER:
    case SUBMARINE:
    case DESTROYER:
        hit = 1;
        break;

    case HIT:
    case MISS:
    default:
        hit = -1;
        break;
    }

    return hit;
}

/**
 * Function name : play()
 * Usage         : play (Cell **, gridBox,short,short[NUM_OF_SHIPS], char, int);
 * Definition    : function that prompts user for input target and simulates game play 
 * Return : void
 */
void play(Cell **gameBoard, gridBox target, short shot, short sunkShip[NUM_OF_SHIPS], char symbol, bool cheated)
{

    int score = 100;
    int numberofHits = 0;
    while (score != 0 && numberofHits != 17)
    {
        // loop while input invalid
        do
        {
            // promp user target and map to grid box
            target = getTarget();
            // verify if location target is valid craft
            shot = checkShot(gameBoard, target);
            if (shot == -1)
                printf("> Try inputting another target!\n");
        } while (shot == -1);
        symbol = gameBoard[target.row][target.column].symbol;
        if (shot == 1)
        { /* HIT */
            printf("> %c%d is a hit!\n", target.row + 65, target.column);
            numberofHits += 1;
            checkSunkShip(sunkShip, symbol);
        }
        else
        { /* MISS */
            printf("> %c%d is a miss!\n", target.row + 65, target.column);
            score -= 1;
        }

        //updateGameboard
        updateGameBoard(gameBoard, target);

        systemMessage("> Hit <ENTER> to continue!\n");
        system("cls");
    }

    playerPtr.score = score;
    if (cheated == true)
    {
        systemMessage("> Cheating Detected. Score Not Saved. Hit <ENTER> to continue!\n");
        system("cls");
    }
    else
    {
        save();
    }
}

/**
 * Function name : checkSunkShip()
 * Usage         : checkSunkShip (short[NUM_OF_SHIPS], char);
 * Definition    : function to check whether a specific water craft has been sunk 
 * Return : bool
 */
bool checkSunkShip(short sunkShip[NUM_OF_SHIPS], char shipSymbol)
{
    bool sunked = false;

    switch (shipSymbol)
    {
    case CARRIER:
        if (--sunkShip[0] == 0)
            printf("> Carrier sunked!\n");
        sunked = true;
        break;

    case BATTLESHIP:
        if (--sunkShip[1] == 0)
            printf("> Battleship sunked!\n");
        sunked = true;
        break;

    case CRUISER:
        if (--sunkShip[2] == 0)
            printf("> Cruiser sunked!\n");
        sunked = true;
        break;

    case SUBMARINE:
        if (--sunkShip[3] == 0)
            printf("> Submarine sunked!\n");
        sunked = true;
        break;

    case DESTROYER:
        if (--sunkShip[4] == 0)
            printf("> Destroyer sunked!\n");
        sunked = true;
        break;
    }

    return sunked;
}

/**
 * Function name : systemMessage()
 * Usage         : systemMessage ();
 * Definition    : helper funtion for logging information during play 
 * Return : void
 */
void systemMessage(char *message)
{
    char ch = '\0';

    do
    {
        printf("%s", message);
    } while ((ch = getch()) != '\r');
}
