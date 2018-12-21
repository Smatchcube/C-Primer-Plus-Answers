#include <stdio.h>

void print_char_rectangle(char ch, int width, int height);

int main(void)
{
	char ch;
	int width, height;

	printf("Enter a character and two integers: ");
	while (ch = getchar(), scanf("%d%d", &width, &height) != 2) {
		while (getchar() != '\n')
			continue; // clean rest of bad input
		printf("Wrong input.\n"
		       "Input should look like: p 9 3\n"
		       "Try again: ");
	}
	print_char_rectangle(ch, width, height);
	printf("\nBye.\n");
	return 0;
}

void print_char_rectangle(char ch, int width, int height)
{
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j)
			putchar(ch);
		putchar('\n');
	}
}
