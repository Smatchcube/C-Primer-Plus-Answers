#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;
	unsigned number_of_lowercase_letters = 0;
	unsigned number_of_uppercase_letters = 0;
	unsigned other_characters = 0;
	printf("Enter some text: ");
	while ((ch = getchar()) != EOF) {
		if (islower(ch))
			number_of_lowercase_letters++;
		else if (isupper(ch))
			number_of_uppercase_letters++;
		else
			other_characters++;
	}
	printf("There are %u lowercase letters, %u uppercase letters and %u other characters.\n",
			number_of_lowercase_letters,
			number_of_uppercase_letters,
			other_characters);
	return 0;
}
