#include <stdio.h>

int main(void) /* this converts my age in years to days */
{
	int years = 19;
	int days = years * 365;

	printf("You are %d years old, that means you has spent approximately %d days on earth.\n", years, days);

	return 0;
}
