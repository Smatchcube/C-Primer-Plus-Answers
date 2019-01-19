#include <stdio.h>
#include <ctype.h>

void getword(char *);

int main(void)
{
	char arr[20];
	puts("Enter some text: ");
	getword(arr);
	printf("The first word you entered is \"%s\".\n", arr);
	return 0;
}

void getword(char *ar)
{
	char ch;
	while (isspace(ch = getchar()))
		continue; // wait until a word begin
	*ar++ = ch;
	while (!isspace(ch = getchar()))
		*ar++ = ch;
	*ar = '\0';
}
