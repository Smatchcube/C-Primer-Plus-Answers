#include <stdio.h>

int main(void) // convert your age in year to seconds
{
	short unsigned int years;
	unsigned long int seconds;

	printf("What is you age: ");
	scanf("%hd", &years);

	seconds = years * 3.156e7;
	printf("You lived %lu seconds on earth.\n", seconds);

	return 0;
}
