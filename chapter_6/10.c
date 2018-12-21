#include <stdio.h>

int sum_of_squares(int, int);

int main(void) // compute the sum of squares
{
	int lower = 0, upper = 1;
	int sum;

	printf("Enter lower and upper integer limits: ");
	scanf("%d%d", &lower, &upper);
	while (lower < upper) {
		printf("The sums of the squares from "
		       "%d to %d is %d\n",
		       lower * lower, upper * upper,
		       sum_of_squares(lower , upper));
		printf("Enter next set of limits: ");
		scanf("%d%d", &lower, &upper);
	}
	printf("Done\n");
	return 0;
}

int sum_of_squares(int lower, int upper) 
{
	int sum = 0;
	for (int i = lower; i <= upper; i++)
		sum += i * i;
	return sum;
}
