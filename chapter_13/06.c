#include <stdio.h>
#include <sdlib.h>
#include <string.h>

int count_char(char, FILE *);

int main(int argc, char **argv)
{
	char ch;
	char tmp;
	FILE * fp;
	int count = 0;
	
	if (argc == 1) { // no argument
		printf("Usage (count char from stdin): %s char\n", argv[0]);
		printf("Usage (count char from files): %s char file1 file2 file3 ...\n", argv[0]);
		return 0;
	}
	if (strlen(argv[1]) != 1) {
		puts("The first argument must be a single character.");
		return 0;
	}	
	
	ch = argv[1][0];
	
	if (argc == 2) {
		printf("Enter your text (Ctrl-d to stop) :");
		while ((tmp = getchar()) != EOF) {
			if (tmp == ch)
				++count;
		}
	} else if (argc >= 3) {
		for (i = 2; i < argc; ++i) {
			if ((fp = fopen(argv[i], "r")) == NULL)
				printf("Can't open %s for read.\n", argv[i]);
			else
				printf("File %s contains %d characters\"%c\"",
					argv[i], count_char(ch, argv[i]), ch);
		}
	}
	puts("Done.");
	return 0;
}
