#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

FILE * printline(FILE *fp);

int main(int argc, char *argv[])
{
	char ch;
	FILE *fp1, *fp2;
	bool fp1_eof, fp2_eof;
	fp1_eof = fp2_eof = false;
	
	if (argc != 3) {
		printf("Usage: %s file1 file2\n", argv[0]);
		return 0;
	}	

	if ((fp1 = fopen(argv[1], "r") == NULL) {
		printf("Error, can't open %s for read.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((fp2 = fopen(argv[2], "w") == NULL) {
		printf("Error, can't open %s for read.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while ((fp1 = printline(fp1)) != NULL && (fp2 = printline(fp2)) != NULL)
		continue;
	while (fp1 != EOF)
		fp1 = printline(fp1);
	while (fp2 != EOF)
		fp2 = printline(fp2);

	fclose(fi);
	fclose(fo);
	
	return 0;
}

FILE * printline(FILE *fp)
{
	char ch;
	while ((ch = getc(fp)) != EOF && ch != '\n')
		putchar(ch);
	if (ch == '\n') {
		putchar('\n');
		return fp;
	else {
		putchar('\n');
		return NULL
	}
}
	
