/* must be compiled with 5_stack.c */
#include <stdio.h>
#include <stdbool.h>
#include "5_stack.h"

int main(void)
{
	char ch;
	Stack stack;

	InitializeStack(&stack);
	printf("Enter a line of text: ");
	while ((ch = getchar()) != '\n')
		PushItem(ch, &stack);
	while (PopItem(&ch, &stack))
		putchar(ch);

	puts("\nBye");
	return 0;
}
