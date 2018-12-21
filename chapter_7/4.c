#include <stdio.h>

int main(void)
{
	char ch;
	int substitution_count = 0;
	printf("Enter some text (# to stop): ");
	while ((ch = getchar()) != '#') {
		if (ch == '.') {
			putchar('!');
			substitution_count++;
		} else if (ch == '!') {
			printf("!!");
			substitution_count++;
		} else {
			putchar(ch);
		}
	}
	printf("\nWe did %d substitution%s\n", substitution_count, 
					       (substitution_count == 1) ? "." : "s.");
	return 0;
} 
