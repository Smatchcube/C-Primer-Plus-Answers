#include <stdio.h>

int main(void) // convert cups in other in pints, ounces, tablespoons and teaspoons
{
	float cups, pints, ounces, tablespoons, teaspoons;
	printf("Enter a volume in cups: ");
	scanf("%f", &cups);

	pints = cups / 2;
	ounces = cups * 8;
	tablespoons = ounces * 2;
	teaspoons = tablespoons * 3;

	printf("This is equal to:\n%f pints\n%f ounces\n%f tablespoons\n%f teaspoons\n",
		pints, ounces, tablespoons, teaspoons);

	return 0;
}
/* It makes more sense to use a floating-point type 
 * because volumes are not always integers and we can get round-off errors 
 * for pints when we divide by 2 (because not every integer is even!). */
