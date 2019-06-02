#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 5

struct names {
	char first[40];
	char last[40];
};

void showarray(const struct names ar[], int n);
int mycomp(const void * p1, const void * p2);

int main(void)
{
	struct names vals[NUM] = {
		{"Theodore", "Kaczynski"},
		{"Alan", "Turing"},
		{"David", "Kaczynski"},
		{"Marty", "McFly"},
		{"Cave", "Johnson"}
	};
	puts("Name list:");
	showarray(vals, NUM);
	qsort(vals, NUM, sizeof(struct names), mycomp);
	puts("Sorted name list:");
	showarray(vals, NUM);
	return 0;
}

void showarray(const struct names ar[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("\t%s %s\n", ar[i].first, ar[i].last);
}

int mycomp(const void * p1, const void * p2)
{
	const struct names *ps1 = (const struct names *) p1;
	const struct names *ps2 = (const struct names *) p2;
	int res;
	res = strcmp(ps1->last, ps2->last);
	if (res != 0)
		return res;
	else
		return strcmp(ps1->first, ps2->first);
}
