#include <stdio.h>

int main(void)
{
	int character_count = 0;
	char ch;
	int i = 0;

	while ((ch = getchar()) != '#') {
		if (character_count++ % 8 == 0)
			printf("\n");
		printf(" \'%c\' : %d  ", ch, ch);
	}
	printf("\n");
	return 0;
}
