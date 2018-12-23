#include <stdio.h>
#define SIZE 5
void sum_arrays(
	int size,
	const int source1[size],
	const int source2[size],
	int result[size]);

int main(void)
{
	int arr1[SIZE] = {0, 2, 4, 6, 8};
	const int arr2[SIZE] = {1, 3, 5, 7, 9};
	int sum[SIZE];
	sum_arrays(SIZE, arr1, arr2, sum);
	putchar('{');
	for (int i = 0; i < SIZE; ++i) {
		printf("%d, ", sum[i]);
	}
	printf("\b\b  \b\b}\n");
	return 0;
}

void sum_arrays(
	int size,
	const int source1[size]
	,const int source2[size],
	int result[size])
// vector sum
{
	for (int i = 0; i < size; ++i) {
		result[i] = source1[i] + source2[i];
	}
}
