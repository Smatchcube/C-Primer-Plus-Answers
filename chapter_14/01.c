#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int nb_days_up_to(char * month);
char * s_gets(char * st, int n);

struct month {
	char name[10];
	char abbrev[4];
	int days;
	int monumb;
};

const struct month months[12] = {
	{"January", "jan", 31, 1},
	{"February", "feb", 28, 2},
	{"March", "mar", 31, 3},
	{"April", "apr", 30, 4},
	{"May", "may", 31, 5},
	{"June", "jun", 30, 6},
	{"July", "jul", 31, 7},
	{"August", "aug", 31, 8},
	{"September", "sep", 30, 9},
	{"October", "oct", 31, 10},
	{"November", "nov", 30, 11},
	{"December", "dec", 31, 12}
};

int main(void)
{
	char month[10];
	printf("Enter the name of the month: ");
	s_gets(month, 10);
	printf("There are %d days in the year up to and including that month.\n",
	       nb_days_up_to(month));
	return 0;
}

int nb_days_up_to(char * month)
{
	int nb_days = 0;
	bool month_seen = false;
	for (int i = 0; i < 12 && !month_seen; ++i) {
		nb_days += months[i].days;
		if (strcmp(month, months[i].name) == 0)
			month_seen = true;
	}
	return month_seen ? nb_days : -1; // return -1 in case month was invalid
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
