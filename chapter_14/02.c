#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int nb_days_up_to(int day, char * month, int year);
bool is_leap(int year);
bool is_integer(char *);
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
	int day;
	char month[10];
	int year;
	printf("Enter the day number: ");
	scanf("%d", &day);
	while (getchar() != '\n')
		continue; // get rid of spaces
	printf("Enter the month (number, abreviation or full name): ");
	s_gets(month, 10);
	printf("Enter the year: ");
	scanf("%d", &year);
	printf("There are %d days in the year up to and including that day.\n",
	       nb_days_up_to(day, month, year));
	return 0;
}

int nb_days_up_to(int day, char * month, int year)
{
	int nb_days = 0;
	int monumb = -1;
	bool month_correct = false;
	if (is_integer(month)) {
		monumb = atoi(month);
		if (monumb >= 1 && monumb <= 12)
			month_correct = true;
	} else {
		*month = tolower(*month);
		for (int i = 0; i < 12; ++i) {
			if (strncmp(month, months[i].abbrev, 3) == 0) {
				monumb = i+1;
				month_correct = true;
			}
		}
	}
	printf("%d\n", monumb);
	for (int i = 0; i < monumb - 1; ++i) {
		nb_days += months[i].days;
	}
	nb_days += day;
	if (is_leap(year) && monumb > 2)
		nb_days += 1; // count 29 February
	return month_correct ? nb_days : -1; // return -1 in case month was invalid
}

bool is_leap(int year)
{
	if (year%4 != 0)
		return false;
	else if (year%100 != 100)
		return true;
	else if (year%400 != 400)
		return false;
	return true;
}

bool is_integer(char * str)
{
	while (*str) {
		if (!isdigit(*str++))
			return false;
	}
	return true;
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
