#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

const float ARTICHOKES_PRICE_PER_POUNDS = 2.05;
const float BEETS_PRICE_PER_POUNDS      = 1.15;
const float CARROTS_PRICE_PER_POUNDS    = 1.09;

float ask_pounds(char[]);

int main(void)
{
	char vegetable_choice;
	bool user_still_ordering = true;
	float artichokes_pounds, beets_pounds, carrots_pounds;
	float cost_artichokes_order, cost_beets_order, cost_carrots_order;
	float cost_vegetables;
	float discount;
	float total_pounds;
	float shipping_costs;
	float grand_total;
	artichokes_pounds = beets_pounds = carrots_pounds = 0;

	while (user_still_ordering) {
		printf(" *** Choose the vegetable you want to order ***\n"
		       "a for artichokes, b for beets, c for carrots and q to exit the ordering process.\n"
		       "input: ");
		while ((vegetable_choice = getchar()) == '\n')
			continue; // clear newlines in input buffer and prompt a char
		switch (vegetable_choice) {
		case 'a':
			artichokes_pounds += ask_pounds("artichokes");
			break;
		case 'b':
			beets_pounds += ask_pounds("beets");
			break;
		case 'c':
			carrots_pounds += ask_pounds("carrots");
			break;
		case 'q':
			user_still_ordering = false;
			break;
		default:
			printf("please enter a correct action\n");
		}
	}
	
	cost_artichokes_order = artichokes_pounds * ARTICHOKES_PRICE_PER_POUNDS;
	cost_beets_order = beets_pounds * BEETS_PRICE_PER_POUNDS;
	cost_carrots_order = carrots_pounds * CARROTS_PRICE_PER_POUNDS;

	cost_vegetables = cost_artichokes_order + cost_beets_order + cost_carrots_order;
	if (cost_vegetables >= 100)
		discount = 0.05 * cost_vegetables;
	else 
		discount = 0;

	total_pounds = artichokes_pounds + beets_pounds + carrots_pounds;
	if (total_pounds <= 5.00)
	       shipping_costs = 6.50;
	else if (total_pounds <= 20.00)
		shipping_costs = 14.00;
	else
		shipping_costs = 14.00 + 0.50 * (total_pounds - 20.00);

	grand_total = cost_vegetables - discount + shipping_costs;
	
	if (total_pounds <= 0) {
		printf("Bye\n");
		return 0;
	}

	printf("\n      ***  Purchase informations  ***\n");
	if (artichokes_pounds > 0)
		printf("%.2f pounds of artichokes for $%.2f per pounds: $%.2f\n",
		       artichokes_pounds, ARTICHOKES_PRICE_PER_POUNDS, cost_artichokes_order);
	if (beets_pounds > 0)
		printf("%.2f pounds of beets for $%.2f per pounds: $%.2f\n",
		       beets_pounds, BEETS_PRICE_PER_POUNDS, cost_beets_order);
	if (carrots_pounds > 0)
		printf("%.2f pounds of carrots for $%.2f per pounds: $%.2f\n",
		       carrots_pounds, CARROTS_PRICE_PER_POUNDS, cost_carrots_order);
	if (discount > 0)
	printf("Discount: $%.2f\n", discount);
	printf("Shipping costs: $%.2f\n", shipping_costs);
	printf("Grand total: $%.2f\n", grand_total);
	printf("Thank you for your visit.\n");
	return 0;
}

float ask_pounds(char product_name[])
{
	float pounds;
	printf("Enter how many pounds of %s you want: ", product_name);
	scanf("%f", &pounds);
	return pounds;
}



