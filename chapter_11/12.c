#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define LENGTH 500

int main(void)
{
	char s[LENGTH];
	int words, upper, lower, punct, digits;
	bool in_word = false;
	char *ptr;
	words = upper = lower = punct = digits = 0;
	puts("Enter some text (EOF to finish):");
	while (fgets(s, LENGTH, stdin)) {
		ptr = s;
		while (*ptr) {
			if (isalpha(*ptr) && !in_word) {
				in_word = true;
				++words;
			} else if (isspace(*ptr)) {
				in_word = false;
			}
			if (islower(*ptr))
				++lower;
			if (isupper(*ptr))
				++upper;
			if (ispunct(*ptr))
				++punct;
			if (isdigit(*ptr))
				++digits;
			++ptr;
		}
	}
	printf("Words count: %d\n"
	       "Lowercase letters: %d\n"
	       "Uppercase letters: %d\n"
	       "Punctuation characters: %d\n"
	       "Number of digits: %d\n",
	       words, lower, upper, punct, digits);
	puts("Bye");
	return 0;
}
