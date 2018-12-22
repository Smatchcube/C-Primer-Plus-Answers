#include <stdio.h>

void larger_of(double *, double *);

int main(void)
{
	double x, y;

	printf("x = ");
	scanf("%lf", &x);
	printf("y = ");
	scanf("%lf", &y);

	larger_of(&x, &y);
	printf("x = %f\ny = %f\n", x, y);

	return 0;
}

void larger_of(double * x, double * y)
{
	if (*x > *y)
		*y = *x;
	else
		*x = *y;
}
