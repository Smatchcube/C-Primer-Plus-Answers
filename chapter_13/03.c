#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 90

char * s_gets(char *, int);

int main(void)
{
	char ch;
	FILE *fi, *fo;
	char input_filename[SLEN], output_filename[SLEN];

	printf("Enter the name of the source file: ");
	s_gets(input_filename, SLEN);
	printf("Enter the name of the output file: ");
	s_gets(output_filename, SLEN);
	
	if ((fi = fopen(input_filename, "r")) == NULL) {
		printf("Error, can't open %s for read.\n", input_filename);
		exit(EXIT_FAILURE);
	}
	if ((fo = fopen(output_filename, "w")) == NULL) {
		printf("Error, can't open %s for write.\n", output_filename);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fi)) != EOF)
		putc(toupper(ch), fo);
	
	fclose(fi);
	fclose(fo);
	
	return 0;
}
	
char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
