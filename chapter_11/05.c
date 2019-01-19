#include <stdio.h>
#include <string.h>
#define SIZE 100

char *mystrchr(char *, char);

int main(void)
{
	char arr[SIZE];
	char c;
	char *ptr;
	puts("Enter some text: ");
	while (fgets(arr, SIZE, stdin), strcmp(arr, "q\n")) {
		puts("Enter a character: ");
		c = getchar();
		getchar();
		if (ptr = mystrchr(arr, c))  // only if c is found
			printf("End of line starting from %c: %s", c, ptr);
		else
			puts("Character not found.");
		puts("Enter another text (q to quit): ");
	}
	return 0;
}

char *mystrchr(char *s, char c)
{
	while (*s) {
		if (*s == c)
			return s;
		++s;
	}
	return NULL;
}
