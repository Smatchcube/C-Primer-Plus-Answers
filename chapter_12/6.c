#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array_stat(int size, const int arr[size]);
void randomize_array(unsigned seed, int size, int *);

int main(void)
{
	int array[10][1000];
	for (int i = 0; i < 10; ++i)
		randomize_array(i, 1000, array[i]);
	printf("Seed |");
	for (int i = 1; i < 11; ++i)
		printf("#%-4d", i);
	printf("\n     |------------------------------------------------\n");
	for (int i = 0; i < 10; ++i) {
		printf("  %d  |", i);
		print_array_stat(1000, array[i]);
	}

	return 0;
}

void randomize_array(unsigned seed, int size, int *arr)
{
	srand(seed);
	for (int i = 0; i < size; ++i)
		arr[i] = (rand() % 10) + 1;
}

void print_array_stat(int size, const int arr[size])
{
	int count[11] = { 0 };
	for (int i = 0; i < size; ++i)
		++count[arr[i]];
	for (int i = 1; i < 11; ++i)
		printf("%-5d", count[i]);
	printf("\b\n");
}
