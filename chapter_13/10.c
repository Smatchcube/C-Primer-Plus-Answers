#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 90

char * s_gets(char *, int);

int main(void)
{
	char name[SLEN];
	FILE *fp;
	long pos;
	char ch;
	
	printf("Enter the name of the file: ");
	s_gets(name, SLEN);
	if ((fp = fopen(name, "r")) == NULL) {
		printf("Can't open %s for read.\n", name);
		exit(EXIT_FAILURE);
	}
	
	printf("Enter a file position (out of bound position to quit): ");
	scanf("%Ld", &pos);
	while (fseek(fp, pos, SEEK_SET) == 0) {
		while ((ch = getc(fp)) != EOF && ch != '\n')
			putchar(ch);
		printf("\nEnter the nex position (out of bound to quit): ");
		scanf("%Ld", &pos);
	}
	
	fclose(fp);
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
