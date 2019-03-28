#include <stdio.h>
#include <stdlib.h>
#define SLEN 90

int main(void)
{
	int ch;
	FILE *fp;
	unsigned long count = 0;
	const char filename[SLEN];
	fputs("Enter a filename: ", stdout);
	scanf("%s",filename);
	if ((fp = fopen(filename, "r")) == NULL) {
		printf("Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF) {
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters.\n", filename, count);
	return 0;
}
