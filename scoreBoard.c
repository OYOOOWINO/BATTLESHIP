#include "battle.h"

/**
 * Function name : scoreBoard()
 * Usage         : scoreBoard();
 * Definition    : Function enables reads user stats from file and print to console 
 * Return : none
 */
void scoreBoard()
{
    struct player stats;

    FILE *playerStats;
    // Open log file for reading
    playerStats = fopen("playerStats.log", "r");
    if (playerStats == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }

    // read file contents till end of file
    while (fread(&stats, sizeof(struct player), 1, playerStats))
        printf("\nName: %s\nCountry: %s\nDate: %s\nScore: %d\n\n", stats.name,
               stats.country, stats.date, stats.score);

    // close file
    fclose(playerStats);
}
