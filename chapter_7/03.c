#include <stdio.h>

int main(void)
{
	int odd_count, odd_sum, even_count, even_sum;
	odd_count = odd_sum = even_count = even_sum = 0;
	int n;

	printf("Enter some numbers (0 to stop): ");

	while (scanf("%d", &n) == 1 && n != 0) {
		if (n % 2 == 0) {
			even_count++;
			even_sum += n;
		} else {
			odd_count++;
			odd_sum += n;
		}
	}
	printf("Number of even integers: %d\n"
	       "Number of odd integers: %d\n",
	       even_count, odd_count);
	if (even_count != 0)
		printf("Average value of even integers: %f\n",
				(float) even_sum / even_count);
	if (odd_count != 0)
		printf("Average value of odd integers: %f\n",
				(float) odd_sum / odd_count);
	return 0;
}
