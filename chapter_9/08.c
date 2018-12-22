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
	double pow = 1;

	if (p > 0) {
		for (int i = 1; i <= p; ++i)
			pow *= n;
	} else if (p < 0) {
		if (n == 0) {
			printf("0 to a negative power is undefined.\n"
			       "Using a value of inf.\n");
		}
		p = -p;
		for (int i = 1; i <= p; ++i)
			pow *= n;
		pow = 1 / pow;
	} else if (p == 0 && n == 0) {
		printf("pow(0, 0) is undefined.\n"
		       "Using a value of 1.\n");
	}

	return pow;
}
