#include<stdio.h>

double min(double x, double y);

int main(void)
{
	double x, y;
	printf("Enter a pair of numbers (q to quit): ");
	while (scanf("%lf %lf", &x, &y) == 2) {
		printf("min(%f,%f) = %f\n", x, y, min(x,y));
		printf("Enter another pair of numbers (q to quit): ");
	}
	printf("Bye.\n");
	return 0;
}

double min(double x, double y)
{
	return x < y ? x : y;
}
