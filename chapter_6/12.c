#include <stdio.h>

int main(void)
{
	int upper, sign;
	float sum_1, sum_2, term;

	printf("Enter the number of terms to evaluate: ");
	while (scanf("%d", &upper) == 1) {
		sum_1 = 0;
		sum_2 = 0;
		for (int k = 1, sign = 1; k <= upper; k++, sign *= -1) {
			term = (float) 1 / k;
			sum_1 += term;
			sum_2 += sign * term;
		}
		printf("The %dth partial sum of the harmonic series "
		       "is equal to %f.\n", upper, sum_1);
		printf("The %dth partial sum of the alternating "
		       "harmonic series is equal to %f.\n", upper, sum_2);
		printf("Enter the next number of terms to evaluate "
		       "(q to quit): ");
	}
	return 0;
}
/* The first sum seems divergent and is indeed divergent (harmonic series).
 * The second sum seems to be converging and is indeed converging to ln(2).*/
