#include <stdio.h>

int main(void)
{
	int count, sum, upper;

	count = 0;
	sum = 0;
	printf("Enter an integer: ");
	scanf("%d", &upper);
	while (count++ < upper)
		sum = sum + count * count;
	printf("sum of squares = %d\n", sum);

	return 0;
}
/* We could also use the fact that the sum of the first
 * n integers is equal to n * (n + 1) * (2 * n + 1) / 6
 * This is obviously not the point of the exercise.
*/
