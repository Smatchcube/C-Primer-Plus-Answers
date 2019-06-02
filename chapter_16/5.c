#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void print_picks(const int *, int size, int nb_picks);

int main(void)
{
	srand(time(0));
	int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	print_picks(digits, 10, 5);
	return 0;
}

void print_picks(const int *arr, int size, int nb_picks)
{
	bool not_picked[size];
	for (int i = 0; i < size; ++i)
		not_picked[i] = true;
	
	int index;

	putchar('[');
	while (nb_picks > 0) {
		if (not_picked[index = rand() % size]) {
			printf("%d ,", arr[index]);
			not_picked[index] = false;
			--nb_picks;
		}
	}
	printf("\b\b]\n");
}
