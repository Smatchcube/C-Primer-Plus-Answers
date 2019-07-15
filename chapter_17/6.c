#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define MIN 0
#define MAX 20

int binary_search(int size, int [size], int);
int comp_int(const void *, const void *);

int main(void)
{
	int arr[SIZE];
	int my_int;
	
	srand(time(0));
	
	for (int i = 0; i < SIZE; ++i)
		arr[i] = rand() % (MAX + MIN) - MIN;

	qsort(arr, SIZE, sizeof(int), comp_int);
	printf("Here is the array of random numbers:\n{");
	for (int i = 0; i < SIZE; ++i)
		printf("%d, ", arr[i]);
	printf("\b\b}\nEnter an integer:");

	while (scanf("%d", &my_int) == 1) {
		if (binary_search(SIZE, arr, my_int))
			printf("%d is in this array\n", my_int);
		else
			printf("%d is not in this array\n", my_int);
		printf("Enter another number (non numeric value to quit): ");
	}
	
	return EXIT_SUCCESS;
}

int comp_int(const void * p1, const void * p2)
{
	return *(int*)p1 - *(int*)p2;
}

int binary_search(int size, int arr[size], int my_int)
{
	int left = 0;
	int right = size - 1;
	int mid;
	
	while (left <= right) {
		mid = (left + right) / 2;
		if (my_int > arr[mid])
			left = mid + 1;
		else if (my_int < arr[mid])
			right = mid - 1;
		else
			return 1;
	}
	return 0;
}
