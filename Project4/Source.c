#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crtdbg.h>

#define  ARR_SIZE 21

typedef struct player {
	char name[ARR_SIZE]; // player's name, up to 20 chars
	int age; // player's age, 0 - 120
	int defense; // defense power, 1 - 100
	int attack; // attack power, 1 - 100
	struct player* next; // next player in the list
}player;


typedef struct team {
	char name[ARR_SIZE]; // team's name
	player *teamPlayers; // pointer to the team players list
	int points; // the team points in the league
	int wins; // number of wins
	int draws; // number of draws
	int losses; // number of losses
	struct team* next; // Next team in the list
}team;


team* create_team(char name[],player *teamPlayers, int points,int wins,int draws, int losses,struct team* next)
{
	team team = { name,teamPlayers,points,wins,draws,losses,next };
}

player* create_player(char name[], int age, int defense, int attack, struct player* next)
{
	player player = { name, age, defense,  attack,next };
}

int str_cut(char* str, int begin, int len)
{
	int l = strlen(str);

	if (len < 0) len = l - begin;
	if (begin + len > l) len = l - begin;
	memmove(str + begin, str + begin + len, l - len + 1);

	return len;
}


int main(int argc, char* argv[]) {
	FILE *fTeams = fopen(argv[0], "r");
	FILE *fPlayers = fopen(argv[1], "r");
	FILE *fGames = fopen(argv[2], "r");
	FILE *fTable = fopen(argv[3], "w");
	FILE* fResult = fopen("results.txt", "w");
	team *t_head = NULL, *new_team = NULL;
	player *p_head = NULL, *new_player = NULL;
	char line[]="";
	char name[] = "";
	while (fgets(line, sizeof line, fTeams) != NULL) 
	{
		new_team = malloc(sizeof(team));
		for (int i = 0; i < ARR_SIZE-2; i++) {
			if ((line[i]==" ")&&(line[i+1] == " ")) {
				char name[] = str_cut(line, 0, i);
				break;
			}
		}
		player *teamPlayers = NULL;
		new_team = create_team(name,teamPlayers,0,0,0,0,t_head);
		t_head = new_team;
	}
	fclose(fTeams);

	while (fgets(line, sizeof line, fPlayers) != NULL)
	{
		//NEED TO ADD EACH TEAM IT'S PLAYERS
	}
	fclose(fPlayers);
	
	return 0;
}