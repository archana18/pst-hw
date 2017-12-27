
struct  Player
{
	int offensive ;
	int defensive;
	int number;
	int team;
	char *first;
	char *last;
	}k;
typedef struct Player Player;


struct Team
 {
 	char *name;
	Player *players;

 }h;


typedef struct Team Team;
Player * draftPlayers(char * filename, int team, int num_players);
 Team * initializeTeam(char * name, Player * players);

Team * game(Team *to,  Team *td);
	
 Team * tournament(Team **t1, int Not) void deleteTeam(Team *t);
