#include <stdio.h>

double diff_largest_smallest(int size, const double [size]);

int main(void)
{
	double arr1[] = {1, 2.4, 2};
	const double arr2[] = {-1, 5.5, 7.5, 1};
	printf("Difference of max and min of arr1 = %f\n",
	       diff_largest_smallest(3, arr1));
	printf("Difference of max and min of arr2 = %f\n",
	       diff_largest_smallest(4, arr2));
	return 0;
}

double diff_largest_smallest(int size, const double arr[size])
// return the difference of the largest and the smallest element of an array
{
	double max, min, current;
	max = min = arr[0];
	for (int i = 1; i < size; ++i) {
		current = arr[i];
		if (current > max)
			max = current;
		else if (current < min)
			min = current;
	}
	return max - min;
}
