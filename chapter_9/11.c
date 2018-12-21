#include <stdio.h>

unsigned long Fibonacci(unsigned);

int main(void)
{
	unsigned n;

	printf("Enter a positive integer (q to quit): ");
	while (scanf("%u", &n) == 1)
		printf("Fibonacci(%u) = %lu\n", n, Fibonacci(n));
	printf("Bye.\n");

	return 0;
}

unsigned long Fibonacci(unsigned n)
{
	unsigned long old_term, new_term, temp;
	old_term = 0;
	new_term = 1;
	if (n == 0)
		return 0;
	n--;
	while (n--) {
		temp = new_term;
		new_term += old_term;
		old_term = temp;
	}
	return new_term;
}
