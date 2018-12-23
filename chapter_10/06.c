#include <stdio.h>
#define SIZE1 4
#define SIZE2 7
void reverse(int size, double [size]);
void print_array(int size, const double [size]);

int main(void)
{
	double arr1[SIZE1] = {1, 3.14, 9.9999, 0};
	printf("Array_1 before reversing : ");
	print_array(SIZE1, arr1);
	reverse(SIZE1, arr1);
	printf("Array_1 after reversing  : ");
	print_array(SIZE1, arr1);

	double arr2[SIZE2] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	printf("Array_2 before reversing : ");
	print_array(SIZE2, arr2);
	reverse(SIZE2, arr2);
	printf("Array_2 after reversing  : ");
	print_array(SIZE2, arr2);
}

void reverse(int size, double arr[size])
// reverse the content of the array
{
	double temp;
	for (int i = 0; i < size / 2; ++i) {
		temp = arr[i];
		arr[i] = arr[size-i-1];
		arr[size-i-1] = temp;
	}
}


void print_array(int size, const double arr[size])
// print the content of an array of doubles (literal representation)
{
	putchar('{');
	for (int i = 0; i < size; ++i) {
		printf("%f, ", arr[i]);
	}
	printf("\b\b  \b\b}\n"); // remove last ',' and ' ' char and close curly brackets
}
