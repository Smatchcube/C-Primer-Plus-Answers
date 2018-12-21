#include <stdio.h>

int main(void)
{
	char old_char, new_char;
	int ei_count = 0;
	old_char = 'a';
	
	printf("Enter some text (# to quit): ");
	while ((new_char = getchar()) != '#') {
		if (old_char == 'e' && new_char == 'i')
			ei_count++;
		old_char = new_char;
	}
	printf("\"ei\" appears %d time%s\n", ei_count, (ei_count == 1) ? "." : "s.");
	return 0;
}
