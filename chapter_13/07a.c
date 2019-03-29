#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool readline(FILE *fp); // read a line of a file and return
			 // wether the end of file was reach or not

int main(int argc, char * argv[])
{
	FILE *fp1, *fp2;
	bool fp1_ended, fp2_ended;
	fp1_ended = fp2_ended = false;

	if (argc != 3) {
		printf("Usage: %s file1 file2\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	if ((fp1 = fopen(argv[1], "r")) == NULL) {
		printf("Can't open %s for read.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((fp2 = fopen(argv[2], "r")) == NULL) {
		printf("Can't open %s for read.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while (!fp1_ended && !fp2_ended) {
		fp1_ended = readline(fp1);
		fp2_ended = readline(fp2);
	}
	if (!fp1_ended) {
		while (!fp1_ended)
			fp1_ended = readline(fp1);
	} else if (!fp2_ended) {
		while (!fp2_ended)
			fp2_ended = readline(fp2);
	}

	puts("Done");
	return 0;
}

bool readline(FILE *fp)
{
	char ch, last;
	if ((ch = getc(fp)) != EOF) {
		putchar(ch);
		while ((ch = getc(fp)) != EOF && ch != '\n') {
			last = ch;
			putchar(ch);
		}
		putchar('\n');
	}
	return (ch == EOF) ? true : false;
}
