#include <stdio.h>
#include <limits.h>
#define UINT_BIT sizeof(unsigned) * CHAR_BIT

void rotate_l(unsigned *, unsigned r);
char * itobs(unsigned, char *);

int main(void)
{
	int a = 65504;
	char bs[UINT_BIT+1];
	printf("%s\n", itobs(a, bs));
	rotate_l(&a, 1);
	printf("%s\n", itobs(a, bs));
	rotate_l(&a, 2);
	printf("%s\n", itobs(a, bs));
	rotate_l(&a, 3);
	printf("%s\n", itobs(a, bs));
	rotate_l(&a, 4);
	printf("%s\n", itobs(a, bs));
	rotate_l(&a, 5);
	printf("%s\n", itobs(a, bs));
	rotate_l(&a, 4);
	printf("%s\n", itobs(a, bs));
	rotate_l(&a, 3);
	printf("%s\n", itobs(a, bs));
	rotate_l(&a, 2);
	printf("%s\n", itobs(a, bs));
	rotate_l(&a, 1);
	printf("%s\n", itobs(a, bs));
	return 0;
}

void rotate_l(unsigned * n, unsigned r)
{
	unsigned mask = 1 << (sizeof(*n) * CHAR_BIT - 1);
	while (r--) {
		if ((*n & mask) == mask)
			*n = (*n << 1) + 1;
		else
			*n <<= 1;
	}
}
		
char * itobs(unsigned n, char * bs)
{
	unsigned mask = 1 << (UINT_BIT - 1);
	for (int i = 0; i < UINT_BIT; ++i) {
		bs[i] = '0' + ((n & mask) == mask);
		mask >>= 1;
	}
	bs[UINT_BIT] = '\0';
	return bs;
}
