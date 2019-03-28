#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 80

int main(void)
{
	int ch;
	FILE *fs, *fo;
	char filename[SLEN];
	fputs("Enter the name of the file to copy: ", stdout);
	scanf("%s", filename);
	if ((fs = fopen(filename, "rb")) == NULL) {
		printf("Can't open %s for reading.\n", filename);
		exit(EXIT_FAILURE);
	}
	if ((fo = fopen(strcat(filename,".copy"), "wb")) == NULL) {
		printf("Can't open %s for writting.\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fs)) != EOF)
		putc(ch, fo);
	fclose(fs);
	fclose(fo);
	return 0;
}
