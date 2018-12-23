#include <stdio.h>

int main(void) // asks and prints the first and last name
{
	char first[20], last[20];

	printf("What is your first name?\n");
	scanf("%s", first);
	printf("What is your last name?\n");
	scanf("%s", last);

	printf("%s, %s\n", last, first);

	return 0;
}
