#include <stdio.h>

int main(int argc,char * argv[])
{
	FILE * fp;
	char ch;
	
	if (argc < 2) {
		printf("Usage: %s file1 file2 ...\n", argv[0]);
		return 0;
	}
	
	for (int i = 1; i < argc; ++i) {
		if ((fp = fopen(argv[i], "r")) == NULL)
			printf("Can't open %s for read.\n", argv[i]);
		else {
			while ((ch = getc(fp)) != EOF)
				putchar(ch);
			fclose(fp);
		}
	}
	
	puts("Done");
	return 0;	
}
