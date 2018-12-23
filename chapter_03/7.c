#include <stdio.h>

int main(void) // this program convert centimeters to inches
{
	float centimeters, inches;
	printf("Enter you height in centimeters: ");
	scanf("%f", &centimeters);
	inches = centimeters / 2.54;
	printf("Your height is %f inches.\n", inches);

	return 0;
}
