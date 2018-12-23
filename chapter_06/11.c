#include <stdio.h>

const int SIZE = 8;

int main(void)
{
	int array[SIZE];
	printf("Enter %d integers: ", SIZE);
	for (int i = 0; i < SIZE; i++) 
		scanf("%d", &array[i]);
	for (int i = SIZE - 1; i >= 0; i--)
		printf("%-8d", array[i]);
	printf("\n");
	return 0;
}
