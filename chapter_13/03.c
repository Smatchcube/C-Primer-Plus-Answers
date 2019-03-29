#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SLEN 90

char * s_gets(char *, int);

int main(void)
{
	char sf_name[SLEN], of_name[SLEN];
	FILE *sf, *of;
	char ch;
	
	printf("Enter the name of the source file: ");
	s_gets(sf_name, SLEN);
	if ((sf = fopen(sf_name, "r")) == NULL) {
		printf("Can't open %s for read.\n", sf_name);
		exit(EXIT_FAILURE);
	}
	printf("Enter the name of the output file: ");
	s_gets(of_name, SLEN);
	if ((of = fopen(of_name, "w")) == NULL) {
		printf("Can't open %s for read.\n", of_name);
		exit(EXIT_FAILURE);
	}
	
	while ((ch = getc(sf)) != EOF)
		putc(toupper(ch), of);
		
	fclose(sf);
	fclose(of);
	
	puts("Done");
	return 0;	
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;

	}
}
