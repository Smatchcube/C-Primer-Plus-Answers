#include <stdio.h>

int main(void)
{
	char letter_1, letter_2;
	for (letter_1 = 'F'; letter_1 >= 'A'; letter_1--) {
		for (letter_2 = 'F'; letter_2 >= letter_1; letter_2--)
			printf("%c", letter_2);
		printf("\n");
	}
	return 0;
}
