#include <stdio.h>
#include <ctype.h>

int letter_alphabet_position(char);

int main(void)
{
	char ch, position;
	while ((ch = getchar()) != EOF) {
		position = letter_alphabet_position(ch);
		if (position != -1)
			printf("%c is letter %u.\n",
					ch, letter_alphabet_position(ch));
	}
	return 0;
}

int letter_alphabet_position(char letter)
{
	if (isalpha(letter))
		return tolower(letter) - 'a' + 1;
	return -1;
}
