#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(unsigned int);

int main(void)
{
	unsigned upper_limit = 7919;

	printf("Enter a positive integer: ");
	scanf("%u", &upper_limit);
	for (unsigned i = 2; i <= upper_limit; i++) {
		if (is_prime(i))
			printf("%u\n", i);
	}
	return 0;
}

bool is_prime(unsigned n) 
{
	for (unsigned d = 2; d * d <= n; d++) {
		if (n % d == 0)
			return false;
	}
	return true;
}
