#include <stdio.h>

const int SIZE = 8;

int main(void)
{
	double array_1[SIZE], array_2[SIZE];

	printf("Enter %d numbers: ", SIZE);
	for (int i = 0; i < SIZE; i++)
		scanf("%lf", &array_1[i]);
	array_2[0] = array_1[0];
	for (int i = 1; i < SIZE; i++)
		array_2[i] = array_2[i-1] + array_1[i];
	for (int i = 0; i < SIZE; i++)
		printf("%10.4f", array_1[i]);
	printf("\n");
	for (int i = 0; i < SIZE; i++)
		printf("%10.4f", array_2[i]);
	printf("\n");
	return 0;
}
