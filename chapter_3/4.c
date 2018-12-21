#include <stdio.h>

int main(void) // ask a floating-point value and print it in different notations
{
	float my_float;
	printf("Enter a floatting-point value: ");
	scanf("%f", &my_float);

	printf("fixed-point notation: %f\n", my_float);
	printf("exponential notation: %e\n", my_float);
	printf("p notation: %a\n", my_float);

	return 0;
}
