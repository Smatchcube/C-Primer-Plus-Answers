#include <stdio.h>

void sort(double *, double *, double *);

int main(void)
{
	double x, y, z;

	printf("x = ");
	scanf("%lf", &x);
	printf("y = ");
	scanf("%lf", &y);
	printf("z = ");
	scanf("%lf", &z);

	sort(&x, &y, &z);
	printf("x = %f\ny = %f\nz = %f\n", x, y, z);

	return 0;
}

void sort(double * x, double * y, double * z)
{
	double temp;

	if (*x > *z) {
		temp = *x;
		*x = *z;
		*z = temp;
	} 
	if (*x > *y) {
		temp = *x;
		*x = *y;
		*y = temp;
	}
	if (*y > *z) {
		temp = *y;
		*y = *z;
		*z = temp;
	}
}
