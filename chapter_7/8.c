#include <stdio.h>
#include <stdbool.h>

#define PAY_RATE1 8.75
#define PAY_RATE2 9.33
#define PAY_RATE3 10.00
#define PAY_RATE4 11.20
#define OVERTIME_MULTIPLIER 1.5
#define OVERTIME_HOURS 40
#define TAX_RATE1 0.15
#define BREAK1 300.00
#define TAX_RATE2 0.20
#define BREAK2 450.00
#define TAX_RATE3 0.25
#define BASE1 (TAX_RATE1 * BREAK1)
#define BASE2 (BASE1 + TAX_RATE2 * (BREAK2 - BREAK1))

float calculate_gross_pay(float, float);
float calculate_taxes(float);

int main(void)
{
	float hours_of_work, gross_pay, taxes, net_pay, pay_rate;
	int rate_choice;
	
	while (true) {
		printf("*****************************************************************\n"
	               "Enter the number corresponding to the desired pay rate or action:\n"
		       "1) $%.2f/hr                          2) $%.2f/hr\n"
	       	       "3) $%.2f/hr                          4) $%.2f/hr\n"
		       "5) quit\n"
	               "*****************************************************************\n"
		       "input : ",
	               PAY_RATE1, PAY_RATE2, PAY_RATE3, PAY_RATE4);
		scanf("%d", &rate_choice);
		switch (rate_choice) {
		case 1:
			pay_rate = PAY_RATE1;
			break;
		case 2:
			pay_rate = PAY_RATE2;
			break;
		case 3:
			pay_rate = PAY_RATE3;
			break;
		case 4:
			pay_rate = PAY_RATE4;
			break;
		case 5:
			return 0;
		default:
			printf("Choice not available, try again.\n");
			continue;
		}
		printf("Enter the number of hours worked in a week: ");
		scanf("%f", &hours_of_work);
		gross_pay = calculate_gross_pay(hours_of_work, pay_rate);
		taxes = calculate_taxes(gross_pay);
		net_pay = gross_pay - taxes;
		printf("Gross pay : $%.2f\n"
	       	       "Taxes :     $%.2f\n"
	               "Net pay :   $%.2f\n",
	               gross_pay, taxes, net_pay);
	}
}

float calculate_gross_pay(float hours_of_work, float pay_rate)
{
	if (hours_of_work > OVERTIME_HOURS)
		return pay_rate * (OVERTIME_HOURS + 
				        (hours_of_work - OVERTIME_HOURS) * OVERTIME_MULTIPLIER);
	return pay_rate * hours_of_work;
}

float calculate_taxes(float gross_pay)
{
	if (gross_pay <= BREAK1)
		return TAX_RATE1 * gross_pay;
	else if (gross_pay <= BREAK2)
		return BASE1 + (TAX_RATE2 * (gross_pay - BREAK1));
	else
		return BASE2 + (TAX_RATE3 * (gross_pay - BREAK2));
}
