#include <stdio.h>
#define LITERS_PER_GALLON 3.785
#define KILOMETERS_PER_MILE 1.609

int main(void)
{
	float distance, gasoline;
	printf("Enter the number of miles traveled: ");
	scanf("%f", &distance);
	printf("Enter the number of gallons of gasoline consumed: ");
	scanf("%f", &gasoline);

	printf("Miles-per-gallon: %.1f\n", distance / gasoline);
	printf("Liters-per-100-km: %.1f\n",
		(gasoline * LITERS_PER_GALLON * 100) / (distance * KILOMETERS_PER_MILE));

	return 0;
}
