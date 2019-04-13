#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_image_width(FILE *);
int get_image_height(FILE *);

int main(int argc, char * argv[])
{
	FILE *fi, *fo;
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

	int cols = get_image_width(fi);
	int rows = get_image_height(fi);

	int digits[rows][cols];
	char chars[rows][cols+1];

	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			digits[r][c] = getc(fi) - '0';
			getc(fi);
		}
	}
	fclose(fi);
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c)
			chars[r][c] = color[digits[r][c]];
		chars[r][cols] = '\0';
	}
	for (int r = 0; r < rows; ++r) {
		puts(chars[r]);
		fprintf(fo, "%s\n", chars[r]);
	}
	fclose(fo);
	puts("Done");
	return 0;
}

int get_image_width(FILE *fp)
{
	rewind(fp);
	int width = 0;
	while(getc(fp) != '\n')
		++width;
	rewind(fp);
	return (width + 1) / 2; // do not count spaces
}

int get_image_height(FILE *fp)
{
	rewind(fp);
	char ch;
	int height = 0;
	while ((ch = getc(fp)) != EOF) {
		if (ch == '\n')
			++height;
	}
	rewind(fp);
	return height;
}
