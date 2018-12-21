#include <stdio.h>

void Temperatures(double);

int main(void)
{
	double temp;

	printf("Enter a Fahrenheit temperature: ");
	while (scanf("%lf", &temp) == 1) {
		Temperatures(temp);
		printf("Enter a Fahrenheit temperature (q to quit): ");
	}
	printf("Done\n");

	return 0;
}

void Temperatures(double fahrenheit)
{
	const double c1 = 5.0 / 9.0, c2 = 32.0, c3 = 273.16;
	double celcius = c1 * (fahrenheit - c2);
	printf("%.2f °F is also %.2f°C or %.2f K.\n",
			fahrenheit,
			celcius,
			celcius + c3);
}
