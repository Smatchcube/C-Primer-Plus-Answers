#include <stdio.h>

int main(void)
{
	char max_letter;
	int i;
	printf("Enter a letter: ");
	scanf("%c", &max_letter);
	for (char letter = 'A'; letter <= max_letter; letter++) {
		for (i = 1; i <= max_letter - letter; i++)
			printf(" ");
		for (i = 'A'; i <= letter; i++)
			printf("%c", i);
		for (i -= 2; i >= 'A'; i--)
			printf("%c", i);
		printf("\n");
	}
	return 0;
}
