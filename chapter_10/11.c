#include <stdio.h>
#define ROWS 3
#define COLS 5

void double_2D(int rows, int cols, int [rows][cols]);
void print_2D(int rows, int cols, const int [rows][cols]);

int main(void)
{
	int arr[ROWS][COLS] = {
		{1, 2, 3, 4, 5},
		{0, 1, 2, 3, 4},
		{4, 3, 2, 1, 0},
	};
	printf("Array before:\n");
	print_2D(ROWS, COLS, arr);
	double_2D(ROWS, COLS, arr);
	printf("Array after doubling:\n");
	print_2D(ROWS, COLS, arr);
}

void double_2D(int rows, int cols, int arr[rows][cols])
// double the content of the 2D array
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j)
			arr[i][j] *= 2;
	}
}

void print_2D(int rows, int cols, const int arr[rows][cols])
// print the 2D array (literal representation)
{
	printf("{\n");
	for (int i = 0; i < rows; ++i) {
		printf("\t{");
		for (int j = 0; j < cols; ++j)
			printf("%d, ", arr[i][j]);
		printf("\b\b  \b\b},\n");
	}
	printf("\b\b  \b\b\n}\n");
}
