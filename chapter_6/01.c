#include <stdio.h>

int main(void)
{
	char alphabet[26];
	char letter;
	int i;

	for (letter = 'a', i = 0; letter <= 'z'; letter++, i++) {
		alphabet[i] = letter;
		printf("%c\n", alphabet[i]);
	}
	return 0;
}
