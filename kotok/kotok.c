// Anisa Skenderovic 000457599

#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include "kotok.h"

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


Player* initPlayerTab(int players)
{
  Player *PlayerTab = calloc(players, sizeof(Player));

  if (PlayerTab == NULL)
  {
    exit(0);
  }

  return PlayerTab;
}


void delPlayerTab(Player *PlayerTab)
{
  free(PlayerTab);
}


Player* addPlayerToTab(Player *PlayerTab, int players)
{
  PlayerTab = realloc(PlayerTab, players * sizeof(Player));
  PlayerTab[players-1].id_player = 0;

  return PlayerTab;
}


int queryValues(FILE* partiesFile, Player *PlayerTab, char *line, int players)
{
  int i = 0;
  int a = 0;
  char *id_player = calloc(2, sizeof(char));
  char *id_player_two = calloc(2, sizeof(char));
  char *score = calloc(4, sizeof(char));

    while (line[i] != ' ')
    {
      id_player[i] = line[i];
      i += 1;
    }

    i += 1;

    while (line[i] != ' ')
    {
      id_player_two[a] = line[i];
      i += 1;
      a += 1;
    }

      i += 1;
      a = 0;

    while (i < 9 && a < 4)
    {
        score[a] = line[i];
        a += 1;
        i += 1;
    }

    players = addID(PlayerTab, atoi(id_player), players);
    players = addID(PlayerTab, atoi(id_player_two), players);
    addScore(PlayerTab, atof(score), atoi(id_player), atoi(id_player_two));

    return players;
}


int queryLines(FILE* partiesFile, Player *PlayerTab, int players)
{

    char *line = calloc(9, sizeof(char));

    while (fgets(line, 9, partiesFile) != NULL && ftell(partiesFile) != EOF)
    {
      printf("%d, %d, %d, %d, %d, %d, %d, %d, %d\n", line[0], line[1], line[2], line[3], line[4], line[5], line[6], line[7], line[8] );
      players = queryValues(partiesFile, PlayerTab, line, players);
    }

    return players;
}


void addScore(Player *PlayerTab, float score, int id_player, int id_player_two)
{
  PlayerTab[id_player].id_player = id_player;
  PlayerTab[id_player_two].id_player = id_player_two;


  if (score == 0)
  {
    PlayerTab[id_player_two].score += 1;
    PlayerTab[id_player_two].wonParties += 1;
  }

  if (score == 1)
  {
    PlayerTab[id_player].score += 1;
    PlayerTab[id_player].wonParties += 1;
  }

  if (score == 0.5)
  {
    PlayerTab[id_player].score += 0.5;
    PlayerTab[id_player_two].score += 0.5;
  }

  printf("id %d\n", PlayerTab[id_player].id_player );
  printf("id two %d\n", PlayerTab[id_player_two].id_player);
  printf("score %f\n",PlayerTab[id_player].score );
  printf("score 2 %f\n",PlayerTab[id_player_two].score );
}

int addID(Player *PlayerTab, int id_player, int players)
{

  if (players < id_player)
  {
    players = id_player;
    PlayerTab = addPlayerToTab(PlayerTab, players * sizeof(Player));
  }
  return players;

}

void writeInFile(Player *PlayerTab, FILE* performanceFile, int players)
{
  int line = 0;
  char score[10] = "";
  char id_p[2] = "";

  for (line; line <= players; ++line)
  {
    if (PlayerTab[line].id_player > 0 && PlayerTab[line].id_player <= players)
    {
      printf("%d %d\n", line, PlayerTab[line].id_player);
      sprintf(id_p, "%d", PlayerTab[line].id_player);
      fputs(id_p, performanceFile);
      printf("TRue id %s\n", id_p);

      sprintf(score, "%f", PlayerTab[line].score);
      printf("score %s\n", score);

    }
  }
}