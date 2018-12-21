#include <stdio.h> 

int main(void) // a small character counting programm, works like wc -m < filename
{
	unsigned number_of_characters = 0;
	while (getchar() != EOF)
		number_of_characters++;
	printf("There are %u characters.\n", number_of_characters);
	return 0;
}
