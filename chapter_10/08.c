#include <stdio.h>

void copy_arr(int size, int target[size],const int source[size]);

int main(void)
{
	int arr1[7] = {0, 1, 2, 3, 4, 5, 7};
	int arr2[3];
	copy_arr(3, arr2, arr1 + 3);
	for (int i = 0; i < 3; ++i)
		printf("%d ", arr2[i]);
	putchar('\n');
}


void copy_arr(int size, int target[size],const int source[size])
// copy content of the source array to target
{
	for (int i = 0; i < size; ++i) {
		target[i] = source[i];
	}
}
