#include <stdio.h>

const int SIZE = 8;

int main(void)
{
	int array[SIZE];

	array[0] = 1;
	for (int i = 1; i < SIZE; i++) 
		array[i] = array[i-1] * 2;
	int i = 0;
	do 
		printf("%-5d", array[i++]);
	while (i < SIZE);
	printf("\n");
	return 0;
}
