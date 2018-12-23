#include <stdio.h>

int max(int size,const int arr[size]);

int main(void)
{
	int arr1[] = {1, 2, 3, 4};
	const int arr2[] = {1, 2, 3, 2, 1};
	printf("Largest value of arr1 = %d.\n",
	       max(4, arr1));
	printf("Largest value of arr2 = %d.\n",
	       max(5, arr2));

	return 0;
}

int max(int size, const int arr[size])
// return the largest int a an array
// note that it also works for const arrays
{
	int max = arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
