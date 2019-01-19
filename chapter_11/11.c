#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define LENGTH 100

char prompt_menu_choice(void);
void print_strings(int nb_strings, const char [nb_strings][LENGTH]);
void print_ASCII_collating_sequence(int nb_strings, const char [nb_strings][LENGTH]);
void print_in_ascending_order(int nb_strings, const char [nb_strings][LENGTH]);
void print_in_ascending_first_word_length(int nb_strings, const char [nb_strings][LENGTH]);
size_t size_word(const char *);

int main(void)
{
	char s[10][LENGTH];
	int nb_strings = 0;
        char menu_choice;
	bool want_to_quit = false;
	puts("Reading 10 strings or until EOF:");
	while (nb_strings < 10 && fgets(s[nb_strings], LENGTH, stdin))
		++nb_strings;
	while (!want_to_quit) {
		menu_choice = prompt_menu_choice();
		switch(menu_choice) {
		case 'q':
			want_to_quit = true;
			break;
		case 'a':
			print_strings(nb_strings, s);
			break;
		case 'b':
			print_ASCII_collating_sequence(nb_strings, s);
			break;
		case 'c':
			print_in_ascending_order(nb_strings, s);
			break;
		case 'd':
			print_in_ascending_first_word_length(nb_strings, s);
			break;
		default:
			puts("Action requested not found.");
		}
	}
	puts("Bye");
	return 0;
}

char prompt_menu_choice(void)
{
	char c;
	printf("Enter the letter corresponding to the desired action:\n"
	       "a) print strings                b) print ASCII values\n"
	       "c) print sorted by length       d) print by length of first word\n"
	       "q) quit\n"
	       "input: ");
	scanf("%c", &c);
	while (getchar() != '\n')
		continue;
	return c;
}

void print_strings(int nb_strings, const char s[nb_strings][LENGTH])
{
	for (int i = 0; i < nb_strings; ++i)
		fputs(s[i], stdout);
}

void print_ASCII_collating_sequence(int nb_strings, const char s[nb_strings][LENGTH])
{
	const char * ptr;
	for (int i = 0; i < nb_strings; ++i) {
		ptr = s[i];
		while (*ptr)
			printf("%d ", *ptr++);
		printf("\b\n");
	}
}

void print_in_ascending_order(int nb_strings, const char s[nb_strings][LENGTH])
{
	const char* p[nb_strings];
	const char* tmp;
	for (int i = 0; i < nb_strings; ++i)
		p[i] = s[i];
	for (int i = 0; i < nb_strings; ++i) {
		for (int j = i; j < nb_strings; ++j) {
			if (strlen(p[j]) < strlen(p[i])) {
				tmp = p[j];
				p[j] = p[i];
				p[i] =tmp;
			}
		}
		fputs(p[i], stdout);
	}
}

void print_in_ascending_first_word_length(int nb_strings, const char s[nb_strings][LENGTH])
{
	const char* p[nb_strings];
	const char* tmp;
	for (int i = 0; i < nb_strings; ++i)
		p[i] = s[i];
	for (int i = 0; i < nb_strings; ++i) {
		for (int j = i; j < nb_strings; ++j) {
			if (size_word(p[j]) < size_word(p[i])) {
				tmp = p[j];
				p[j] = p[i];
				p[i] =tmp;
			}
		}
		fputs(p[i], stdout);
	}
}

size_t size_word(const char *s)
{
	size_t i = 0;
        while (!isspace(s[i]))
	        ++i;
        return i;
}
