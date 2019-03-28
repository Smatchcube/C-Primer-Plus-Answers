#include <stdlib.h>
#include <stdio.h>

void print_file(FILE *);

int main(int argc, char * argv[])
{
	FILE *fp;
	for (int i = 1; i < argc; ++i) {
		if ((fp = fopen(argv[i], "r")) == NULL) {
			printf("Can't open %s for read.\n", argv[i]); 
			exit(EXIT_FAILURE);
		} else
			print_file(fp);
	}
	fclose(fp);
	puts("Done.");
	return 0;
}

void print_file(FILE *fp)
{
	char ch;
	while ((ch = getc(fp)) != EOF)
		putc(ch, fp);
}

