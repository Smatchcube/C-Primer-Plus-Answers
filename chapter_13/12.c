#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 20
#define COLS 30

int main(int argc, char * argv[])
{
	FILE *fi, *fo;
	int digits[ROWS][COLS];
	char chars[ROWS][COLS+1];
	char ch;
	const char color[10] = {' ', '.', '\'', ':', '-', '*', '=', '@' , '%', '#'};

	if (argc != 2) {
		printf("Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fi = fopen(argv[1], "r")) == NULL) {
		printf("Can't open file %s for read.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((fo = fopen("output.img", "w")) == NULL) {
		printf("Can't open file %s for write.\n", "output.img");
		exit(EXIT_FAILURE);
	}
	
	for (int r = 0; r < ROWS; ++r) {
		for (int c = 0; c < COLS; ++c) {
			digits[r][c] = getc(fi) - '0';
			getc(fi);
		}
	}
	fclose(fi);
	for (int r = 0; r < ROWS; ++r) {
		for (int c = 0; c < COLS; ++c)
			chars[r][c] = color[digits[r][c]];
		chars[r][COLS] = '\0';
	}
	for (int r = 0; r < ROWS; ++r) {
		puts(chars[r]);
		fprintf(fo, "%s\n", chars[r]);
	}
	fclose(fo);
	puts("Done");
}

