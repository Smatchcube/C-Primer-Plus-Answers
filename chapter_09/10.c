#include <stdio.h>

void to_base_n(unsigned long n, unsigned base);

int main(void)
{
	unsigned long n;
	unsigned base;

	printf("Enter a positive integer and a base in the range 2-8: ");
	while (scanf("%lu %u", &n, &base) != 2 && 2 <= base && base <= 8) {
		while (getchar() != '\n')
			continue; // clear bad input
		printf("Wrong input.\nTry again: ");
	}

	printf("%lu in base %u is ", n, base);
	to_base_n(n, base);
	putchar('\n');

	return 0;
}

void to_base_n(unsigned long n, unsigned base)
{
	int r;

	r = n % base;
	if (n >= base)
		to_base_n(n / base, base);
	putchar('0' + r);
}
