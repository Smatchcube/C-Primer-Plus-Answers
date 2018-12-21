#include <stdio.h>

int main(void)
{
	int lower_bound = 1;
	int upper_bound = 100;
	int guess = (lower_bound + upper_bound) / 2; 
	int ch;

	printf("Pick an integer from %d to %d. I will try to guess it.\n",
	       lower_bound, upper_bound);
	printf("Respond with an l if my guess is low, with an h if "
	       "my guess is high and c if my guess is correct.\n");
	printf("Uh...is your number %d?\n", guess);
	while ((ch = getchar()) != 'c') {
		while (getchar() != '\n')
			continue; /* clean rest of line */
		switch (ch) {
		case 'l':
			lower_bound = guess;
			break;
		case 'h':
			upper_bound = guess;
			break;
		default:
			printf("Please enter a valid response.\n");
			continue;
		}
		guess = (lower_bound + upper_bound) / 2;
		printf("Well, then, is it %d?\n", guess);
	}
	printf("I knew I could do it!\n");

	return 0;
}
