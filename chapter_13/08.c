#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
	char ch;
	char ch_to_count;
	unsigned count = 0;
	FILE * fp;

	if (argc < 2) {
		printf("Usage: %s char [files]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (strlen(argv[1]) != 1) {
		printf("First argument should be a single character\n");
		exit(EXIT_FAILURE);
	}
	ch_to_count = argv[1][0];
	if (argc == 2) {
		printf("Enter text, Ctrl-d to stop: ");
		while ((ch = getchar()) != EOF) {
			if (ch == ch_to_count)
				++count;
		}
		printf("\nYour text have %u occurrence of the \"%c\" character.\n",
				count, ch_to_count);
	} else {
		for (int index_file = 2; index_file < argc; ++index_file) {
			if ((fp = fopen(argv[index_file], "r")) == NULL) {
				printf("Can't open %s for read.\n", argv[index_file]);
			} else {
				while ((ch = getc(fp)) != EOF) {
					if (ch == ch_to_count)
						++count;
				}
				printf("File %s have %u occurrence of the \"%c\""
				       " character.\n", argv[index_file],
				       count, ch_to_count);
				count = 0;
				fclose(fp);
			}
		}
	}

	puts("Done");
	return 0;
}
