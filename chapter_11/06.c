#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 500

bool is_within(char, const char *);

int main(void)
{
	char s[SIZE];
	char c;
	printf("Enter some text: ");
	while (fgets(s, SIZE, stdin), strcmp(s, "q\n")) {
		printf("Enter a character: ");
		c = getchar();
		getchar(); // discard newline char
		printf("%c is%s in the string.\n", c, is_within(c, s) ? "" : " not");
		printf("Enter some text (q to quit): ");
	}
	puts("Bye");
	return 0;
}

bool is_within(char c, const char *str)
{
	while (*str) {
		if (c == *str)
			return true;
		str++;
	}
	return false;
}
