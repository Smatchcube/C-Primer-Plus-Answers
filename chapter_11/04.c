#include <stdio.h>
#include <ctype.h>
#define SIZE 5

void getword(char *, int);

int main(void)
{
	char arr[SIZE];
	puts("Enter some text: ");
	getword(arr, SIZE-1);
	printf("The first word you entered is \"%s\".\n", arr);
	return 0;
}

void getword(char *ar, int n)
{
	char ch;
	int i = 0;
	while (isspace(ch = getchar()))
		continue; // wait until a word begin
	*ar++ = ch;
	while (!isspace(ch = getchar()) && i++ < n)
		*ar++ = ch;
	*ar = '\0';
}
