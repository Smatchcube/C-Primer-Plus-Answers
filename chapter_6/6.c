#include <stdio.h>

int main(void)
{
	int lower, upper;
	printf("Enter the lower limit integer: ");
	scanf("%d", &lower);
	printf("Entet the upper limit integer: ");
	scanf("%d", &upper);
	printf("+---------+---------+---------+\n"
	       "|    n    |   n^2   |   n^3   |\n"
	       "+---------+---------+---------+\n");
	for (int i = lower; i <= upper; i++)
		printf("|%8d |%8d |%8d |\n", i, i*i, i*i*i);
	printf("+---------+---------+---------+\n");
	return 0;
}
