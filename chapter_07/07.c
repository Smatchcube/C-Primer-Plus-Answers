#include <stdio.h>
#define BASIC_PAY_RATE 10.00
#define OVERTIME_MULTIPLIER 1.5
#define OVERTIME_HOURS 40
#define RATE1 0.15
#define BREAK1 300.00
#define RATE2 0.20
#define BREAK2 450.00
#define RATE3 0.25
#define BASE1 (RATE1 * BREAK1)
#define BASE2 (BASE1 + RATE2 * (BREAK2 - BREAK1))

float calculate_gross_pay(float);
float calculate_taxes(float);

int main(void)
{
	float hours_of_work, gross_pay, taxes, net_pay;

	printf("Enter the number of hours worked in a week: ");
	scanf("%f", &hours_of_work);
	gross_pay = calculate_gross_pay(hours_of_work);
	taxes = calculate_taxes(gross_pay);
	net_pay = gross_pay - taxes;
	printf("Gross pay : $%.2f\n"
	       "Taxes :     $%.2f\n"
	       "Net pay :   $%.2f\n",
	       gross_pay, taxes, net_pay);
	return 0;
}

float calculate_gross_pay(float hours_of_work)
{
	if (hours_of_work > OVERTIME_HOURS)
		return BASIC_PAY_RATE * (OVERTIME_HOURS + 
				        (hours_of_work - OVERTIME_HOURS) * OVERTIME_MULTIPLIER);
	return BASIC_PAY_RATE * hours_of_work;
}

float calculate_taxes(float gross_pay)
{
	if (gross_pay <= BREAK1)
		return RATE1 * gross_pay;
	else if (gross_pay <= BREAK2)
		return BASE1 + (RATE2 * (gross_pay - BREAK1));
	else
		return BASE2 + (RATE3 * (gross_pay - BREAK2));
}
