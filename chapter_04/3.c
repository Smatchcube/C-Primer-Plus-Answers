#include <stdio.h>

int main(void)
{
	float value;

	printf("Enter a floating-point number: ");
	scanf("%f", &value);

	printf("The input %.1f or %.1e.\n", value, value);
	printf("The input is %+.3f or %.3E.\n", value, value);

	return 0;
}
