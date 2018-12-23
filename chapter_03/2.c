#include <stdio.h>

int main(void) // ask ASCCI code value and display the associated character
{
	char my_character;

	printf("Enter an ASCII code value: \a");
	scanf("%d", &my_character);

	printf("The ASCII code value %d is associated to the '%c' character.\n", my_character, my_character);

	return 0;
}
