// Anisa Skenderovic 000457599

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "tableau.h"

int main(int argc, char* argv[])
{
  FILE* partiesFile = NULL;
  char* partiesPath = argv[1];
  char* performancePath = argv[2];

  partiesFile = fopen(partiesPath, "r");
  if (partiesFile == NULL)
  {
    printf("Impossible de lire le fichier \n");
    exit(0);
  }

  int *players = malloc(sizeof(int));
  if (players == NULL)
  {
    perror("Unable to allocate memory");
    fclose(partiesFile);
    exit(0);
  }

  *players = INIT_NB_PLAYER;
  Player *PlayerTab = initPlayerTab(INIT_NB_PLAYER);
  PlayerTab = queryLines(partiesFile, PlayerTab, players);
  fclose(partiesFile);

  FILE* performanceFile = fopen(performancePath, "w");
  writeInFile(PlayerTab, performanceFile, *players);
  fclose(performanceFile);


  delPlayerTab(PlayerTab, players);
  return 0;

}
