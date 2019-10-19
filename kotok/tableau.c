// Anisa Skenderovic 000457599


#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "tableau.h"


Player* initPlayerTab(int players)
{
  Player *PlayerTab = calloc(players, sizeof(Player));

  if (PlayerTab == NULL)
  {
    exit(0);
  }

  return PlayerTab;
}


void delPlayerTab(Player *PlayerTab, int *players)
{
  free(PlayerTab);
}


Player* addPlayerToTab(Player *PlayerTab, int players)
{
  PlayerTab = realloc(PlayerTab, players * sizeof(Player));

  return PlayerTab;
}


void delPlayersIds(char *id_player, char *id_player_two, char *score)
{
  free(id_player);
  free(id_player_two);
  free(score);
}


Player* queryValues(FILE* partiesFile, Player *PlayerTab, char *line, int *players)
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
    PlayerTab = addID(PlayerTab, atoi(id_player), players);
    PlayerTab = addID(PlayerTab, atoi(id_player_two), players);
    addScore(PlayerTab, atof(score), atoi(id_player), atoi(id_player_two));

    delPlayersIds(id_player, id_player_two, score);


    return PlayerTab;
}


Player* queryLines(FILE* partiesFile, Player *PlayerTab, int *players)
{
    printf("Lecture des scores du fichier\n");
    char *line = calloc(9, sizeof(char));

    while (fgets(line, 9, partiesFile) != NULL && ftell(partiesFile) != EOF)
    {
      PlayerTab = queryValues(partiesFile, PlayerTab, line, players);
    }

    free(line);

    return PlayerTab;
}


void addScore(Player *PlayerTab, float score, int id_player, int id_player_two)
{

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

}


Player* addID(Player *PlayerTab, int id_player, int *players)
{
  // Assez de place dans le tableau pour cet ID
  if (id_player < *players && id_player != 0 && PlayerTab[id_player].id_player != id_player)
  {
    PlayerTab[id_player].id_player = id_player;
  }

  // On doit agrandir le tableau
  if (*players < id_player && id_player >= 5)
  {
    *players = id_player;
    PlayerTab = addPlayerToTab(PlayerTab, *players);
    PlayerTab[id_player].id_player = id_player;
  }

  return PlayerTab;
}


void writeInFile(Player *PlayerTab, FILE* performanceFile, int players)
{
  printf("Ecriture des performances dans le fichier\n");
  int line = 0;
  char score[10] = "";
  char id_p[2] = "";
  char won_parties[2] = "";

  for (line; line <= players; ++line)
  {
    // Valeur pertinente (pas un joueur non-existant)
    if (PlayerTab[line].id_player > 0 && PlayerTab[line].id_player <= players)
    {
      sprintf(id_p, "%d", PlayerTab[line].id_player);
      fputs(id_p, performanceFile);
      fputs(" ", performanceFile);

      sprintf(score, "%f", PlayerTab[line].score);
      fputs(score, performanceFile);
      fputs(" ", performanceFile);

      sprintf(won_parties, "%d", PlayerTab[line].wonParties);
      fputs(won_parties, performanceFile);
      fputs(" \n", performanceFile);

    }
  }
}
