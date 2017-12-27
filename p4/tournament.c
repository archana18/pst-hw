#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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

int globnot;


enum {  MAXC = 400 };







char (*line)[MAXC] ; const char *token;

Player * draftPlayers(char * filename, int team, int num_players)

{	
	Player *obj;
	obj=malloc(sizeof(Player)*MAXC);
	int i, n = 0; Player *pl; pl=malloc(sizeof(Player)*MAXC);
	FILE *fp = fopen("players.dat","r");

	if (!fp) 
	{  
		fprintf (stderr, "error: file open failed ");
		return 1;
	}

	int count=0 ; char c ;
	for (c = getc(fp); c != EOF; c = getc(fp))
	if (c == '\n')     count = count + 1;
	 
	fclose(fp);

	fp = fopen("players.dat","r");
	if (!(line = malloc (count * sizeof *line))) 
	{ 
		fprintf (stderr, "error: 'lines'.\n");
		return 1;
	}
	while (n < count && fgets (line[n], MAXC, fp)) { 
	char *p = line[n];                  
	for (; *p && *p != '\n'; p++) {}     
	*p = 0, n++;   //free(p);                      
	}

	i=0;

	while(i<n)
	{   

	//printf (" line[%d] : '%s'\n", i + 1, line[i]);


		token = strtok(line[i],",");
		obj[i].team=atoi(token); 
		token = strtok(NULL, ",");
		obj[i].first=token;
		token = strtok(NULL, ",");
		obj[i].last=token;
		token = strtok(NULL, ",");
		obj[i].number=atoi(token);
		token = strtok(NULL, ",");
		obj[i].offensive=atoi(token);
		token = strtok(NULL, ",");
		obj[i].defensive=atoi(token);
		token = strtok(NULL, ",");

		i++;  


	}


	fclose(fp);

	//printf("obj:%d", obj[4].defensive);

	i=0;int j=0;
	for(i=0;i<n;i++)
	{	if(j<num_players)
		{
			if(obj[i].team==team)
			{
				pl[j]=(obj[i]);
				j++;
			}
		}
	
	}
return pl;
}


int isPowerOfTwo(int n)
{
  if (n == 0)
    return 0;
  while (n != 1)
  {
    if (n%2 != 0)
      return 0;
    n = n/2;
  }
  return 1;
}





 Team * initializeTeam(char * name, Player * players)
{

	

	Team *t; t=malloc(sizeof(Team));
	
	t->name=name;
	(t->players)=(players);
	return (t); free(t);



}


 Team * game(Team *to,  Team *td)
{	
	if (!to || !td) {return NULL; printf("popo");  }
	printf("game1");
	int total_defense=0,total_offense=0; int i,j; int rand_no;


	for(i=0;i<10;i++)
	{
		total_defense=total_defense+td[i].players->defensive;
		total_offense=total_defense+to[i].players->offensive;


	}
	printf("game");

	rand_no = (rand() % (total_offense+1));
	if(total_defense<=rand_no) {printf("game2");return to;}
	else return td;

} 




 Team * tournament(Team **t1, int Not) 
{	globnot=Not;
	int b;int rounds=0; int i=0;
	b=isPowerOfTwo(Not);
	Team *winner;
	winner=(malloc(sizeof(Team)*Not));
	if(b==0)
		printf("number of teams is invalid and a NULL pointer");
	else
	{
		rounds=Not-2;
		i=0;int r=0;
		for(r=0;r<=rounds;r++)
		{
			if(r==0)
			{
			winner[r]=*(game(t1[0],t1[1]));
			}
			else{
			winner[r]=*(game(&(winner[r-1]),t1[r+1]));
			}
			
		}
	} printf("\nTR");return winner;

}


void deleteTeam(Team *t)
{
int i;
for (i=1;i<=globnot;i++)
{
free(t[i].name);
free(t[i].players);
}
}





