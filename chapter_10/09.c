#include <stdio.h>
#define ROWS 4
#define COLS 3

void copy_2D_array(
	int rows,
	int cols,
	const double source[rows][cols],
	double target[rows][cols]);
void print_2D_array(int rows, int cols, const double [rows][cols]);

int main(void)
{
	const double arr1[ROWS][COLS] = {
		{0, 1, 0},
		{1, 2, 1},
		{2, 3, 2},
		{3, 4, 3}
	};
	double arr2[ROWS][COLS];
	copy_2D_array(ROWS, COLS, arr1, arr2);
	printf("First array :\n");
	print_2D_array(ROWS, COLS, arr1);
	printf("The copy :\n");
	print_2D_array(ROWS, COLS, arr2);
}

void copy_2D_array(
	int rows,
	int cols,
	const double source[rows][cols],
	double target[rows][cols])
// copy content of source to target
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j)
			target[i][j] = source[i][j];
	}
}

void print_2D_array(int rows, int cols, const double arr[rows][cols])
// print the two dimension array (literal representation)
{
	printf("{");
	for (int i = 0; i < rows; ++i) {
		printf("\n\t{");
		for (int j = 0; j < cols; ++j)
			printf("%f, ", arr[i][j]);
		printf("\b\b  \b\b},"); // clean before closing braces
	}
	printf("\b \b"); // delete last ',' char
	printf("\n}\n");
}
