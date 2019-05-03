#include <stdio.h>

void foo(void);
void bar(void);

int main(void)
{
	int ch;
	void (* pt_fun[2])(void) = {foo, bar}; // array of 2 pointer to function
	printf("Enter 'a' or 'b': ");
	scanf("%c", &ch);
	switch(ch) {
	case 'a':
		pt_fun[0]();
		break;
	case 'b':
		pt_fun[1]();
		break;
	default:
		puts("Input invalid, bye.");
	}
	return 0;
}

void foo(void)
{
	puts("'a' is the first letter of the alphabet.");
}

void bar(void)
{
	puts("'b' is the second letter of the alphabet.");
}
