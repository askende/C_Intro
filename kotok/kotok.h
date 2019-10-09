
#define INIT_NB_PLAYER 5

typedef struct Player Player;

struct Player
{
  int id_player;
  float score;
  int wonParties;
};


Player* initPlayerTab(int players);

void delPlayerTab(Player *PlayerTab);

Player* addPlayerToTab(Player *PlayerTab, int players);

int queryValues(FILE* partiesFile, Player *PlayerTab, char *line, int players);

int queryLines(FILE* partiesFile, Player *PlayerTab, int players);

void addScore(Player *PlayerTab, float score, int id_player, int id_player_two);

int addID(Player *PlayerTab, int id_player, int players);

void writeInFile(Player *PlayerTab, FILE* performanceFile, int players);
