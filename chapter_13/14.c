#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 20
#define COLS 30

void deglitch(int [ROWS][COLS]);

int main(int argc, char * argv[])
{
	FILE *fi, *fo;
	int digits[ROWS][COLS];
	char chars[ROWS][COLS+1];
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

	deglitch(digits);

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
	return 0;
}

void deglitch(int T[ROWS][COLS])
{
	char copy_T[ROWS][COLS];
	float average_neighbors;
	int nb_neighbors;
	for (int c = 0; c < COLS; ++c) {
		for (int r = 0; r < ROWS; ++r)
			copy_T[r][c] = T[r][c];
	}
	for (int c = 0; c < COLS; ++c) {
		for (int r = 0; r < ROWS; ++r) {
			average_neighbors = 0;
			nb_neighbors = 0;
			if (r >= 1) {
				if (abs(copy_T[r-1][c] - copy_T[r][c]) <= 1)
					continue;
				average_neighbors += copy_T[r-1][c];
				++nb_neighbors;
			}
			if (r < ROWS - 1) {
				if (abs(copy_T[r+1][c] - copy_T[r][c]) <= 1)
					continue;
				average_neighbors += copy_T[r+1][c];
				++nb_neighbors;
			}
			if (c >= 1) {
				if (abs(copy_T[r][c-1] - copy_T[r][c]) <= 1)
					continue;
				average_neighbors += copy_T[r][c-1];
				++nb_neighbors;
			}
			if (c < COLS - 1) {
				if (abs(copy_T[r][c+1] - copy_T[r][c]) <= 1)
					continue;
				average_neighbors += copy_T[r][c+1];
				++nb_neighbors;
			}
			average_neighbors /= nb_neighbors;
			T[r][c] = (int) (average_neighbors + 0.5); // round average
		}
	}
}
