#include <stdio.h>
#include <string.h>
#define LENGTH 100

const char *string_in(const char *search_in, const char *search_for);

int main(void)
{
	char s1[LENGTH], s2[LENGTH];
	const char *ptr;
	puts ("Enter a string:");
	while (fgets(s1, LENGTH, stdin)[0] != '\n') {
		puts("Enter a string to search:");
		fgets(s2, LENGTH, stdin);
		s2[strlen(s2)-1] = '\0';
		if (ptr = string_in(s1, s2)) {
			puts("End of line beginning from your string found:");
			fputs(ptr, stdout);
		} else {
			puts("String not found.");
		}
		puts("Enter a new string (empty line to quit):");
	}
	return 0;
}

const char *string_in(const char *search_in, const char *search_for)
{
	size_t string_length = strlen(search_for);
	while (*search_in) {
		if (!strncmp(search_in, search_for, string_length))
			return search_in;
		++search_in;
	}
	return NULL;
}
