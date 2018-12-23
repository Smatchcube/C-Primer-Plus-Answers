#include <stdio.h>

void print_cubed(double);

int main(void)
{
	double real;

	printf("Enter a number: ");
	scanf("%lf", &real);
	print_cubed(real);
	
	return 0;
}

void print_cubed(double a)
{
	printf("%f\n", a * a);
}
