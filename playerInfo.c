#include "battle.h"

/**
 * Usage         : playerInfo(struct player);
 * Definition    : prompt user inputs for player infomation
 *                 and save to player struct
 * Return:         none
 */
void playerInfo()
{
    // prompt user inputs
    printf("Enter Name: ");
    scanf("%20s", playerPtr.name);
    printf("Enter Country: ");
    scanf("%20s", playerPtr.country);
    printf("Enter Date: ");
    scanf("%20s", playerPtr.date);

    playerPtr.score = 100;
}