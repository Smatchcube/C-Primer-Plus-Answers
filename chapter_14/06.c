#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct player {
	char first[30];
	char last[30];
	int bats;
	int hits;
	int walks;
	int RBI;
	float batting_average;
};

void set_batting_average(struct player *);
void print_info(struct player);

int main(void)
{
	struct player team[19] = {};
	FILE * fp;
	int player_number;
	struct player player = {};
	float sum_batting_average = 0;
	int nb_players = 0;
	if ((fp = fopen("team.data", "r")) == NULL) {
		printf("Can't open team.data for read.\n");
		exit(EXIT_FAILURE);
	}
	while (fscanf(fp, "%d", &player_number) == 1) {
		fscanf(fp, "%s %s %d %d %d %d\n",
				player.first,
				player.last,
				&player.bats,
				&player.hits,
				&player.walks,
				&player.RBI);
		strcpy(team[player_number].first, player.first);
		strcpy(team[player_number].last, player.last);
		team[player_number].bats += player.bats;
		team[player_number].hits += player.hits;
		team[player_number].walks += player.walks;
		team[player_number].RBI += player.RBI;
	}
	for (player_number = 0; player_number < 19; ++player_number) {
		if (team[player_number].first[0] != '\0') {
			set_batting_average(&team[player_number]);
			sum_batting_average += team[player_number].batting_average;
			++nb_players;
			print_info(team[player_number]);
		}
	}
	printf("Batting average of the team: %.2f\n",
			sum_batting_average / nb_players);
	fclose(fp);
	return 0;
}

void set_batting_average(struct player * plt)
{
	plt->batting_average = plt->hits / (float) plt->bats;
}

void print_info(struct player player)
{
	printf("--- %s %s\n"
	       "              official times at bat: %d\n"
	       "              number of hits: %d\n"
	       "              number of walks: %d\n"
	       "              RBI: %d\n"
	       "              batting average: %.2f\n\n",
	       player.first, player.last, player.bats, player.hits,
	       player.walks, player.RBI, player.batting_average);
}
