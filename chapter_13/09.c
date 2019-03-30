#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
	FILE *fp, *fpr; // fpl to count number of lines
	char words[MAX];
	char ch;
	unsigned line_count = 0;

	if ((fpr = fopen("wordy", "r")) == NULL) {
		fprintf(stdout, "Creating \"wordy\" file.\n");
	} else {
		while ((ch = getc(fpr)) != EOF) {
			if (ch == '\n')
				++line_count;
		}
		fclose(fpr);
	}

	if ((fp = fopen("wordy", "a+")) == NULL) {
		fprintf(stdout, "Can't open \"wordy\" file for write.\n");
		exit(EXIT_FAILURE);
	}
	
	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a line to terminate.");
	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#')) {
		++line_count;
		fprintf(fp, "%u %s\n", line_count, words);
	}

	puts("FIle contents:");
	rewind(fp);
	while (fscanf(fp, "%s", words) == 1) {
		printf("%s ", words);
		fscanf(fp, "%s", words);
		puts(words);
	}
	puts("Done!");
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");

	return 0;
}
