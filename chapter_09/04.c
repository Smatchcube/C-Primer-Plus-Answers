#include <stdio.h>

double harmonic_mean(double, double);

int main(void)
{
	double a, b;
	printf("Enter two nonzero numbers: ");
	while (scanf("%lf %lf", &a, &b) != 2 || a == 0 || b == 0) {
		while (getchar() != '\n')
			continue; // clear wrong input
		printf("Wrong input.\nTry again: ");
	}
	printf("The harmonic mean of %f and %f is %f\n.",
			a, b, harmonic_mean(a, b));   
	return 0;
}

double harmonic_mean(double a, double b)
{
	return 1 / (((1 / a) + (1 / b)) / 2);
}
