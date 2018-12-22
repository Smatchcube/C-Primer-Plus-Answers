#include <stdio.h>

double power(double n, int p);

int main(void)
{
	double n;
	int p;
	printf("Enter two numbers: ");
	scanf("%lf %d", &n, &p);
	printf("pow(%f, %d) = %f\n", n, p, power(n, p));
	return 0;
}

double power(double n, int p)
{
	if (p == 1)
		return n;
	if (p > 1)
		return n * power(n, --p);
	if (p < 0) {
		if (n == 0) {
			printf("0 to a negative power is undefined.\n"
			       "Using a value of inf.\n");
		}
		return 1 / power(n, -p);
	}
	if (n == 0) {
		printf("pow(0, 0) is undefined.\n"
		       "Using a value of 1.\n");
	}
	return 1;
}
