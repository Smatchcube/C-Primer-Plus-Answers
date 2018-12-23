#include <stdio.h>
#define MONTHS 12    // number of months in a year
#define YEARS   5    // number of years of data

void print_rainfall_per_year(
	int first_year,
	int number_of_years,
	const float [number_of_years][MONTHS]);
float yearly_average(int number_of_years,const float [number_of_years][MONTHS]);
void print_monthly_averages(int number_of_years, const float [number_of_years][MONTHS]);

int main(void)
{
	// initializing rainfall data for 2010 - 2014
	const float rain[YEARS][MONTHS] =
		{
			{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
			{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
			{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
			{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
			{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
		};
	print_rainfall_per_year(2010, YEARS, rain);
	printf("\nThe yearly average is %.1f inches.\n\n",
	       yearly_average(YEARS, rain));
	printf("MONTHLY AVERAGES:\n\n");
	print_monthly_averages(YEARS, rain);

	return 0;
}

void print_rainfall_per_year(
	int first_year,
	int number_of_years,
	const float rain[number_of_years][MONTHS])
// print a table of the rainfall per year beginning from first_year (inclusive)
{
	int year, month;
	float total_year;
	printf(" YEAR     RAINFALL  (inches)\n");
	for (year = 0; year < number_of_years; ++year) {
		// for each year, sum rainfall for each month
		for (month = 0, total_year = 0; month < MONTHS; ++month)
			total_year += *(*(rain + year) + month);
		printf("%5d %15.1f\n", first_year + year, total_year);
	}
}

float yearly_average(int number_of_years,const float rain[number_of_years][MONTHS])
{
	float sum = 0;
	for (int year = 0; year < number_of_years; ++year) {
		for (int month = 0; month < MONTHS; ++month)
			sum += rain[year][month];
	}
	return sum / number_of_years;
}


void print_monthly_averages(int number_of_years, const float rain[number_of_years][MONTHS])
// print a table of the monthly average
{
	int year, month;
	float total_month;
 	printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
	for (month = 0; month < MONTHS; ++month) {
		// for each month, sum rainfall over years
		for (year = 0, total_month = 0; year < number_of_years; ++year)
			total_month += *(*(rain + year) + month);
		printf("%4.1f ", total_month/YEARS);
	}
	printf("\n");
}
