#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int tax_category;
	float upper_limit_first_bracket, taxable_income, tax;

	while (true) {
		printf("Choose your category or action.\n"
		       "1) Single		2) Head of Household\n"
		       "3) Married, Joint	4) Married, Separate\n"
		       "5) quit\n"
		       "input: ");
		scanf("%d", &tax_category);
		switch (tax_category) {
		case 1:
			upper_limit_first_bracket = 17850;
			break;
		case 2:
			upper_limit_first_bracket = 23900;
			break;
		case 3:
			upper_limit_first_bracket = 23900;
			break;
		case 4:
			upper_limit_first_bracket = 29750;
			break;
		case 5:
			printf("Done\n");
			return 0;
		default:
			printf("Category or action not available.\n");
			continue;
		}
		printf("Enter your taxable income: ");
		scanf("%f", &taxable_income);
		if (taxable_income < upper_limit_first_bracket)
			tax = 0.15 * taxable_income;
		else
			tax = 0.15 * upper_limit_first_bracket 
			      + 0.28 * (taxable_income - upper_limit_first_bracket);
		printf("You owe $%.2f\n", tax);
	}
}
