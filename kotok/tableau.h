// Anisa Skenderovic 000457599

#ifndef TABLEAU_H
#define TABLEAU_H

#define INIT_NB_PLAYER 5

typedef struct Player Player;

struct Player
{
  int id_player;
  float score;
  int wonParties;
};



Player* initPlayerTab(int players);

void delPlayerTab(Player *PlayerTab, int *players);

Player* addPlayerToTab(Player *PlayerTab, int players);

void delPlayersIds(char *id_player, char *id_player_two, char *score);

Player* queryValues(FILE* partiesFile, Player *PlayerTab, char *line, int *players);

Player* queryLines(FILE* partiesFile, Player *PlayerTab, int *players);

void addScore(Player *PlayerTab, float score, int id_player, int id_player_two);

Player* addID(Player *PlayerTab, int id_player, int *players);

void writeInFile(Player *PlayerTab, FILE* performanceFile, int players);


#endif
