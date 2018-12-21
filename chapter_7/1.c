#include <stdio.h>

int main(void)
{
	int spaces = 0, newlines = 0, characters = 0;
	char ch;

	printf("Enter characters (# to end): ");
	while ((ch = getchar()) != '#') {
		switch(ch) {
		case ' ':
			spaces += 1;
			break;
		case '\n':
			newlines += 1;
			break;
		default:
			characters += 1;
		}
	}
	printf("\nYou entered %d spaces, %d newlines and %d characters.\n",
			spaces, newlines, characters);
	return 0;
}
