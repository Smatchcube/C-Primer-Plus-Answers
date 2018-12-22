#include <stdio.h>

float fun(float, float);

int main(void)
{
	float f1, f2;
	printf("Enter two numbers: ");
	while (scanf("%f%f", &f1, &f2) == 2) {
		printf("%f\n", fun(f1, f2));
		printf("Enter two numbers (enter q to quit): ");
	}
	return 0;
}

float fun(float f1, float f2)
{
	return (f1 - f2) / (f1 * f2);
}
