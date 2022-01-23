#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define ROWS 10
#define COLS 10

#define NUM_OF_SHIPS 5

#define HORIZONTAL 0

#define WATER '~'
#define HIT 'H'
#define MISS 'M'

#define CARRIER 'c'
#define BATTLESHIP 'b'
#define CRUISER 'r'
#define SUBMARINE 's'
#define DESTROYER 'd'

struct player
{
    char name[21];
    char country[21];
    char date[21];
    int score;
};

typedef enum
{
    false,
    true
} bool;

typedef struct
{
    char symbol;
    short length;
    char *name;
} Ship;

typedef struct
{
    int row;
    int column;
} gridBox;

typedef struct
{
    char symbol;
    gridBox position;
} Cell;

struct player playerPtr;
/* FUNCTION PROTOTYPES */
void exit(int i);
void save();
void scoreBoard();
void playerInfo();
void menu();
void initializeBoard(Cell **gameBoard);
void printPopulatedBoard(Cell **gameBoard, bool showPegs);
void placeShip(Cell **gameBoard, Ship ship, gridBox position, int direction);
void populateBoard(Cell **gameBoard, Ship ship[]);
void updateGameBoard(Cell **gameBoard, gridBox target);
void systemMessage(char *message);
void play(Cell **gameBoard, gridBox target, short shot, short sunkShip[NUM_OF_SHIPS], char symbol, bool cheated);
bool checkSunkShip(short sunkShip[NUM_OF_SHIPS], char shipSymbol);
bool positionValid(Cell **gameBoard, gridBox position, int direction, int length);

gridBox generatePosition(int direction, int length);
gridBox getTarget(void);

short checkShot(Cell **gameBoard, gridBox target);
int getRandomNumber(int lowest, int highest);

#endif
