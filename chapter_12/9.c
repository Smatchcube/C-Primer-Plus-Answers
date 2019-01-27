#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char ** p;
	int nb_words;
	char temp_word[40];
	size_t char_array_len;

	printf("How many words do you wish to enter? ");
	scanf("%d", &nb_words);
	p = malloc(nb_words * sizeof(char *));

	for (int i = 0; i < nb_words; ++i) {
		scanf("%39s", temp_word);
		char_array_len = strlen(temp_word) + 1;
		p[i] = malloc(char_array_len * sizeof(char));
		strncpy(p[i], temp_word, char_array_len);
	}

	for (int i = 0; i < nb_words; ++i) {
		puts(p[i]);
		free(p[i]);
	}
	free(p);
	return 0;
}
