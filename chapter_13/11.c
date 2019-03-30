#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main(int argc, char *argv[])
{
	FILE *fp;
	char line[MAX];

	if (argc != 3) {
		printf("Usage: %s string file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[2], "r")) == NULL) {
		printf("Can't open %s for read.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX, fp)) {
		if (strstr(line, argv[1]))
			printf("%s", line);
	}

	fclose(fp);
	puts("Done!");
	return 0;
}
