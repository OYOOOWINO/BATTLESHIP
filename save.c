#include "battle.h"

/**
 * Function name : save()
 * Usage         : save();
 * Definition    : Function enables saves user stats to file 
 * Return : none
 */

void save()
{

    FILE *playerStats;
    playerStats = fopen("playerStats.log", "a");
    if (playerStats == NULL)
    {
        fprintf(stderr, "\nError opend file\n");
        exit(1);
    }

    // write struct to file
    fwrite(&playerPtr, sizeof(struct player), 1, playerStats);

    if (fwrite != 0)
        printf("Stats Saved to file!\n");
    else
        printf("Error writing file !\n");

    // close file
    fclose(playerStats);
}