#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;
	int number_of_pairs_on_current_line = 0;
	
	while ((ch = getchar()) != EOF) {
		number_of_pairs_on_current_line++;
		putchar('(');
		if (isprint(ch)) 
			printf("%c : %d", ch, ch); 
		else if (ch == '\t')
			printf("\t : %d", '\t');
		else if (ch == '\n')
			printf("\\n : %d", '\n');
		else
			printf("^%c : %d", ch + 64, ch);
		printf("),");
		if (number_of_pairs_on_current_line == 10 || ch == '\n') {
			putchar('\n');
			number_of_pairs_on_current_line = 0;
		}
	}
	return 0;
}
