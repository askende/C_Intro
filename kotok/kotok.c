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


  Player *PlayerTab = initPlayerTab(INIT_NB_PLAYER);
  int players = queryLines(partiesFile, PlayerTab, INIT_NB_PLAYER);
  fclose(partiesFile);

  FILE* performanceFile = fopen(performancePath, "w");
  writeInFile(PlayerTab, performanceFile, players);
  fclose(performanceFile);


  delPlayerTab(PlayerTab);
  return 0;

}
