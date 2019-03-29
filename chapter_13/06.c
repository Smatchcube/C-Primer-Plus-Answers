#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 90 // Note: this line was missing in my book

int main()
{
	FILE *in, *out;
	int ch;
	char name[LEN];
	int count = 0;

	printf("Enter filename to reduce: ");
	fgets(name, LEN, stdin);
	if (name[strlen(name)-1] == '\n')
		name[strlen(name)-1] = '\0';
	if ((in = fopen(name, "r")) == NULL) {
		fprintf(stderr, "I couldn't open the file \"%s\"\n",
		name);
		exit(EXIT_FAILURE);
	}
	name[LEN - 5] = '\0';
	strcat(name,".red");
	if ((out = fopen(name, "w")) == NULL) {
		fprintf(stderr,"Can't create output file.\n");
		exit(3);
	}
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr,"Error in closing files\n");
	return 0;
}
