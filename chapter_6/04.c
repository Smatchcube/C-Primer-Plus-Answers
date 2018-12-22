#include <stdio.h>

int main(void)
{
	char letter = 'A';
	int i = 1;
	for (int len = 1; len <= 6; len++) {
		for (int i = 1; i <= len; i++)
			printf("%c", letter++);
		printf("%d\n");
	}
	return 0;
}
