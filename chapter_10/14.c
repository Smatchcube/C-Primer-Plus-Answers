#include <stdio.h>

void prompt_data(int rows, int cols, double [rows][cols]);
double average_row(int cols, const double [cols]);
double average_2D(int rows, int cols, const double [rows][cols]);
double largest_2D(int rows, int cols, const double [rows][cols]);
void report_result(int rows, int cols, const double [rows][cols]);

int main(void)
{
	int rows, cols;
	printf("Enter the number of sets followed by "
	       "the number of numbers per sets: ");
	scanf("%d%d", &rows, &cols);
	double arr[rows][cols];
	prompt_data(rows, cols, arr);
	report_result(rows, cols, arr);
}

void prompt_data(int rows, int cols, double arr[rows][cols])
// prompt user for 3 sets of 5 numbers and fill the array
{
	printf("Enter %d sets of %d numbers:\n", rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j)
			scanf("%lf", &arr[i][j]);
	}
}

double average_row(int cols, const double arr[cols])
// return the average of a row
{
	double sum = 0;
	for (int i = 0; i < cols; ++i)
		sum += arr[i];
	return sum / cols;
}

double average_2D(int rows, int cols, const double arr[rows][cols])
// return the average of a 2D array
{
	double sum = 0;
	for (int i = 0; i < rows; ++i)
		sum += average_row(cols, arr[i]);
	return sum / rows;
}

double largest_2D(int rows, int cols, const double arr[rows][cols])
// return the largest element of a 2D array
{
	double max = arr[0][0];
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (arr[i][j] > max)
				max = arr[i][j];
		}
	}
	return max;
}

void report_result(int rows, int cols, const double arr[rows][cols])
{
	for (int i = 0; i < rows; ++i) {
		printf("The average of the set number %d is %f.\n",
		       i + 1, average_row(cols, arr[i]));
	}
	printf("The total average is %f.\n", average_2D(rows, cols, arr));
	printf("The largest element is %f.\n", largest_2D(rows, cols, arr));
}
