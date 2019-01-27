#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int size, const int arr[size]);
void randomize_array(int size, int *);
void sort_array(int size, int arr[size]);

int main(void)
{
	int array[100];
	randomize_array(100, array);
	sort_array(100, array);
	print_array(100, array);

	return 0;
}

void print_array(int size, const int arr[size])
{
	putchar('[');
	for (int i = 0; i < size; ++i)
		printf("%d, ", arr[i]);
	printf("\b\b]\n");
}

void randomize_array(int size, int *arr)
{
	srand((unsigned int) time(0));
	for (int i = 0; i < size; ++i)
		arr[i] = (rand() % 10) + 1;
}

void sort_array(int size, int arr[size])
{
	int temp;
	for (int i = 0; i < size; ++i) {
		for (int j = i+1; j < size; ++j) {
			if (arr[j] > arr[i]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}
