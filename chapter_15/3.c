#include <stdio.h>

int nb_bits_on(int n);

int main(void)
{
	int n;
	printf("Enter an integer, non-numeric value to quit.\ninput: ");
	while (scanf("%d", &n) == 1)
		printf("%d has %d bits on.\ninput: ", n, nb_bits_on(n));
	puts("Bye");
	return 0;
}

int nb_bits_on(int n)
{
	int nb = 0;
	while (n) {
		nb += n & 1;
		n >>= 1;
	}
	return nb;
}
