#include <stdio.h>

int main(void)
{
	float Daphne_value = 100;
	float Deirdre_value = 100;
	int year = 0;

	while (Deirdre_value <= Daphne_value) {
		Daphne_value += 10;
		Deirdre_value *= 1.05;
		year++;
	}
	printf("Year = %d\n", year);
	printf("Daphne: %f\n", Daphne_value);
	printf("Deirdre: %f\n", Deirdre_value);
	return 0;
}
