#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	char c;
	if (argc == 1 || (argc == 2 && strcmp(argv[1], "-p") == 0)) {
		while ((c = getchar()) != EOF)
			putchar(c);
	} else if (argc == 2) {
		if (strcmp(argv[1], "-l") == 0) {
			while ((c = getchar()) != EOF)
				putchar(tolower(c));
		} else if (strcmp(argv[1], "-u") == 0) {
			while ((c = getchar()) != EOF)
				putchar(toupper(c));
		} else {
			printf("Argument \"%s\" not valid.\n", argv[1]);
		}
	} else {
		puts("Too many arguments.");
	}
	return 0;
}
