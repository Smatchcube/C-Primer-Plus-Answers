#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define MAX_BS 1000

int bstoi(const char *);
char * itobs(int, char *);
char * tail(int n, char *); // remove n first char

int main(int argc, char * argv[])
{
	int a, b;
	int lena, lenb;
	int len;
	char BS_result[MAX_BS];
	if (argc != 3) {
		printf("Usage: %s 10100110 01010101\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	lena = strlen(argv[1]);
	lenb = strlen(argv[2]);
	len = lena > lenb ? lena : lenb;
	a = bstoi(argv[1]);
	b = bstoi(argv[2]);
	printf("%d %d\n", a, b);
	printf("~ (%s) = (%s)\n", argv[1], tail(lena, itobs(~a, BS_result)));
	printf("~ (%s) = (%s)\n", argv[2], tail(lenb, (itobs(~b, BS_result))));
	printf("(%s) & (%s) = (%s)\n", argv[1], argv[2],
	       tail(len, itobs(a & b, BS_result)));
	printf("(%s) | (%s) = (%s)\n", argv[1], argv[2],
	       tail(len, itobs(a | b, BS_result)));
	printf("(%s) ^ (%s) = (%s)\n", argv[1], argv[2],
	       tail(len, itobs(a ^ b, BS_result)));
	return 0;
}

int bstoi(const char * bs)
{
	int return_value = 0;
	for (int n = strlen(bs) - 1; n >= 0; --n) {
		if (*bs++ == '1')
			return_value += 1<<n;
	}
	return return_value;
}

char * itobs(int n, char * ps)
{
	int i;
	const static int size = CHAR_BIT * sizeof(int);

	for (i = size - 1; i >= 0; i--, n >>=1)
		ps[i] = (1 & n) + '0';
	ps[size] = '\0';
	return ps;
}

char * tail(int n, char * ps)
{
	int m = strlen(ps);
	for (int i = 0; i < n; ++i)
		ps[i] = ps[m+i-n];
	ps[n] = '\0';
	return ps;
}
