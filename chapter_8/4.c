#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	int ch;
	unsigned number_of_letters;
	unsigned number_of_words = 0;
	bool in_word = false;

	printf("Enter some text: ");
	while ((ch = getchar()) != EOF) {
		if (isspace(ch)) {
			in_word = false;
		} else {
			number_of_letters++;
			if (!in_word) {
				number_of_words++;
				in_word = true;
			}
		}
	}
	printf("The average number of letters per word is %.2f.\n",
			(float) number_of_letters / number_of_words);
	return 0;
}
