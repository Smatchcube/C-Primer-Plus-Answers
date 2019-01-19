#include <stdio.h>

int main(int argc,char *argv[])
{
	--argc;
	while(argc > 0)
		printf("%s ", argv[argc--]);
	putchar('\n');
	return 0;
}
