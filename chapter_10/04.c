#include <stdio.h>

int index_largest(int size, const double []);

int main(void)
{
	double arr1[] = {2.72, 3.14, 1.62};
	const double arr2[] = {1.1};

	printf("Index of largest element of arr1 = %d.\n",
	       index_largest(3, arr1));
	printf("Index of largest element of arr2 = %d.\n",
	       index_largest(1, arr2));

	return 0;
}

int index_largest(int size, const double arr[])
// return the index of the last largest element of the array
{
	int index_largest = 0;
	double max = arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] > max) {
			max = arr[i];
			index_largest = i;
		}
	}
	return index_largest;
}
