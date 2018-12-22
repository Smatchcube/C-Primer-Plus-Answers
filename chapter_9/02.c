#include <stdio.h>

void chline(char ch, int i, int j);

int main(void)
{
	char ch;
	int column, line;
	printf("Enter a character and two integers: ");
	while (ch = getchar(), scanf("%d %d", &column, &line) != 2) {
		while (getchar() != '\n')
			continue; // clear bad input
		printf("Wrong input.\n"
		       "Input should look like: k 3 7\n"
		       "Try again: ");
	}
	chline(ch, column, line);
	printf("\nBye.\n");
	return 0;
}

void chline(char ch, int i, int j)
{
	for (int k = 0; k < i; ++k)
		putchar(' ');
	for (int k = 0; k < j; ++k)
		putchar(ch);
}
