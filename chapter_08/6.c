#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main(void)
{
	char ch;

	printf("Please enter some text: ");
	ch = get_first();
	printf("The first non-whitespace character you entered is %c.\n", ch);

	return 0;
}

char get_first(void)
{
	int ch;
	while (isspace((ch = getchar ())))
		continue; // get the first non-whitespace character
	while (getchar() != '\n')
		continue; // skip rest of input
	return ch;
}
