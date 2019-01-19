#include <stdio.h>
//#include <string.h>
#define NB_STRING 4
#define STRING_SIZE 40

void remove_spaces(char *);

int main(void)
{
	char T[NB_STRING][STRING_SIZE];
	printf("Enter %d sentence%s:\n", NB_STRING, (NB_STRING > 1) ? "s" : "");
	for (int i = 0; i < NB_STRING; ++i)
		fgets(T[i], STRING_SIZE, stdin);
	puts("Here is what you entered with the spaces removed:");
	for (int i = 0; i < NB_STRING; ++i) {
		remove_spaces(T[i]);
		printf(T[i]);
	}
	puts("Bye");
}

void remove_spaces(char *s)
{
	char *i, *j;
	i = j = s;
	while (*j) {
		if (*j == ' ')
			++j;
		else
			*i++ = *j++;
	}
	*i = '\0';
}
