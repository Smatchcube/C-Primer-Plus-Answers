#include <stdio.h>

void copy_arr(double target[], const double source[], int size);
void copy_ptr(double * target, const double * source, int size);
void copy_ptrs(double * target, const double * source, const double * following_last);
void print_array(const double arr[], int size);

int main(void)
{
	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[5];
	double target2[5];
	double target3[5];
	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source + 5);

	printf("source[5]  = ");
	print_array(source, 5);
	printf("target1[5] = ");
	print_array(target1, 5);
	printf("target2[5] = ");
	print_array(target2, 5);
	printf("target3[5] = ");
	print_array(target3, 5);

	return 0;
}

void copy_arr(double target[],const double source[], int size)
// copy content of the source array to target
{
	for (int i = 0; i < size; ++i) {
		target[i] = source[i];
	}
}

void copy_ptr(double * target, const double * source, int size)
// copy content of the source array to target
{
	for (int i = 0; i < size; ++i) {
		*(target + i) = *(source + i);
	}
}

void copy_ptrs(
	double * target,
	const double * source,
	const double * following_last)
// copy content of the source array to target
{
	for (int i = 0; source + i < following_last; ++i) {
		target[i] = source[i];
	}
}

void print_array(const double arr[], int size)
// print the content of an array of doubles (literal representation)
{
	putchar('{');
	for (int i = 0; i < size; ++i) {
		printf("%f, ", arr[i]);
	}
	printf("\b\b  \b\b}\n"); // delete last ',' and ' ' chars and close curly brackets
}
