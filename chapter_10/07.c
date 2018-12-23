#include <stdio.h>
#define ROWS 3
#define COLS 4

void copy_row(double target[],const double source[], int size);
void copy_2D_array(int rows,
		   int cols,
		   double target[rows][cols],
		   const double source[rows][cols]);
void print_row(int size, const double arr[size]);
void print_2D_array(int rows, int cols, const double [rows][cols]);



int main(void)
// copy content of arr1 to arr2
{
	const double arr1[ROWS][COLS] = {
		{0, 1,  2,  3},
		{4, 5,  6,  7},
		{8, 9, 10, 11}
	};
	double arr2[ROWS][COLS];
	copy_2D_array(ROWS, COLS, arr2, arr1);
	printf("Here is the content of the first array :\n");
	print_2D_array(ROWS, COLS, arr1);
	printf("Here is the content of the copy array :\n");
	print_2D_array(ROWS, COLS, arr2);
}



void copy_arr(double target[],const double source[], int size)
// copy content of the source array to target
{
	for (int i = 0; i < size; ++i) {
		target[i] = source[i];
	}
}

void copy_2D_array(int rows,
		   int cols,
		   double target[rows][cols],
		   const double source[rows][cols])
// copy content of the source array to the target array
{
	for (int i = 0; i < rows; ++i)
		copy_arr(target[i], source[i], cols);
}


void print_row(int size, const double arr[])
// print the content of an array of doubles (literal representation)
{
	putchar('{');
	for (int i = 0; i < size; ++i) {
		printf("%f, ", arr[i]);
	}
	printf("\b\b},\n"); // delete chars before closing the braces
}

void print_2D_array(int rows, int cols, const double arr[rows][cols])
// print the content of a 2D array (literal representation)
{
	printf("{\n");
	for (int i = 0; i < rows; ++i) {
		putchar('\t');
		print_row(cols, arr[i]);
	}
	printf("\b \b"); // remove the last '\n' char
	printf("\b \b"); // remove the last ',' char
	printf("\n}\n");
}
