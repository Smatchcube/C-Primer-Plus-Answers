#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int sides);

int main(void)
{
	int sets, sides, dice, sum;
	srand((unsigned int) time(0));
	printf("Enter the number of sets; enter q to stop: ");
	while (scanf("%d", &sets) == 1) {
		printf("How many sides and how many dice? ");
		scanf("%d%d", &sides, &dice);
		printf("Here are %d set%s of %d %d-sided throw%s.\n",
		       sets, sets > 1 ? "s" : "", dice, sides, dice > 1 ? "s" : "");
		for (int i = 0; i < sets; ++i) {
			sum = 0;
			for (int i = 0; i < dice; ++i)
				sum += roll_dice(sides);
			printf("%4d", sum);
		}
		printf("\nHow many sets? Enter q to stop: ");
	}
	return 0;
}

int roll_dice(int sides)
{
	return (rand() % sides) + 1;
}
