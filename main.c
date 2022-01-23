/**
 * Author Name:
 * Email: <Use only official email address>
 * Date:
 * Program Description:
 * The program contains all the function definition of the prototypes
 listed in battleship.h These are the functions necessary to run 
 the game of Battleship
**/
#include "battle.h"
int main(void)
{

    bool boardInitialized = false;
    bool boardPopulated = false;
    bool hasPlayerInfo = false;
    bool hasCheated = false;

    Cell **gameBoard;
    gameBoard = malloc(sizeof(Cell *) * ROWS);
    for (int e = 0; e < ROWS; e++)
        gameBoard[e] = malloc(sizeof(Cell) * COLS);

    gridBox target; /* x, y value of a target */
    Ship ships[NUM_OF_SHIPS] = {{'c', 5, "Carrier"},
                                {'b', 4, "Battleship"},
                                {'r', 3, "Cruiser"},
                                {'s', 3, "Submarine"},
                                {'d', 2, "Destroyer"}};

    short sunkShip[NUM_OF_SHIPS] = {5, 4, 3, 3, 2}; /* tracks parts of the ship destroyed */
    short shot = 0;                                 /* holds temp value if ship has been shot */

    char shipSymbol = '\0'; /* temporary value to save character symbol of the ship */

    while (1)
    {
        srand((unsigned int)time(NULL));
        int option = 0;
        menu();
        printf("> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            fflush(stdin);
            playerInfo();
            hasPlayerInfo = true;
            break;
        case 2:
            if (hasPlayerInfo == true)
            {
                initializeBoard(gameBoard);
                boardInitialized = true;
            }
            else
                printf("Player information must be provided First\n");
            break;
        case 3:
            if (hasPlayerInfo == true)
                if (boardInitialized == true)
                {
                    populateBoard(gameBoard, ships);
                    boardPopulated = true;
                }
                else
                    printf("Board Must Be initialized First\n");
            else
                printf("Player information must be provided First\n");
            break;
        case 4:
            if (hasPlayerInfo == true)
                if (boardInitialized == true)
                {
                    if (boardPopulated == true)
                    {
                        play(gameBoard, target, shot, sunkShip, shipSymbol, hasCheated);
                    }
                    else
                        printf("Board Must Be Populated First\n");
                }
                else
                    printf("Board Must Be initialized First\n");
            else
                printf("Player information must be provided First\n");
            break;
        case 5:
            if (hasPlayerInfo == true)
                if (boardInitialized == true)
                {
                    if (boardPopulated == true)
                    {
                        hasCheated = true;
                        printPopulatedBoard(gameBoard, true);
                    }
                    else
                        printf("Board Must Be Populated First\n");
                }
                else
                    printf("Board Must Be initialized First\n");
            else
                printf("Player information must be provided First\n");
            break;
        case 6:
            if (hasPlayerInfo == true)
                if (boardInitialized == true)
                    scoreBoard();
                else
                    printf("Board Must Be initialized First\n");
            else
                printf("Player information must be provided First\n");
            break;
        case 7:
            exit(0);
            break;

        default:
            break;
        }
        char ch = '\0';
        printf("HIT ENTER TO CONTINUE");
        do
        {
        } while ((ch = getch()) != '\r');
        system("cls");
        fflush(stdin);
    }
    free(gameBoard);
    return 0;
}