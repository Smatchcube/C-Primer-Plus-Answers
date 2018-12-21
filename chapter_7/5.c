#include <stdio.h>

int main(void)
{
	char ch;
	int substitution_count = 0;
	printf("Enter some text (# to stop): ");
	while ((ch = getchar()) != '#') {
		switch (ch) {
		case '.':
			putchar('!');
			substitution_count++;
			break;
		case '!':
			printf("!!");
			substitution_count++;
			break;
		default:
			putchar(ch);
		}
	}
	printf("\nWe did %d substitution%s\n", substitution_count, 
					       (substitution_count == 1) ? "." : "s.");
	return 0;
} 
