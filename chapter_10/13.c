#include <stdio.h>
#define ROWS 3
#define COLS 5

void prompt_data(double [ROWS][COLS]);           // a.
double average_row(const double [COLS]);         // b.
double average_2D(const double [ROWS][COLS]);    // c.
double largest_2D(const double [ROWS][COLS]);    // d.
void report_result(const double [ROWS][COLS]);   // e.

int main(void)
{
	double arr[ROWS][COLS];
	prompt_data(arr);
	report_result(arr);
}

void prompt_data(double arr[ROWS][COLS])
// prompt user for 3 sets of 5 numbers and fill the array
{
	printf("Enter 3 sets of 5 numbers:\n");
	for (int row = 0; row < ROWS; ++row) {
		for (int col = 0; col < COLS; ++col)
			scanf("%lf", &arr[row][col]);
	}
}

double average_row(const double arr[COLS])
// return the average of a row
{
	double sum = 0;
	for (int col = 0; col < COLS; ++col)
		sum += arr[col];
	return sum / COLS;
}

double average_2D(const double arr[ROWS][COLS])
// return the average of a 2D array
{
	double sum = 0;
	for (int row = 0; row < ROWS; ++row)
		sum += average_row(arr[row]);
	return sum / ROWS;
}

double largest_2D(const double arr[ROWS][COLS])
// return the largest element of a 2D array
{
	double max = arr[0][0];
	for (int row = 0; row < ROWS; ++row) {
		for (int col = 0; col < COLS; ++col) {
			if (arr[row][col] > max)
				max = arr[row][col];
		}
	}
	return max;
}

void report_result(const double arr[ROWS][COLS])
{
	for (int row = 0; row < ROWS; ++row) {
		printf("The average of the set number %d is %f.\n",
		       row + 1, average_row(arr[row]));
	}
	printf("The total average is %f.\n", average_2D(arr));
	printf("The largest element is %f.\n", largest_2D(arr));
}
