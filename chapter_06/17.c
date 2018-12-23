#include <stdio.h>

int main(void)
{
	double account = 1e6;
	int year = 0;
	while (account > 0) {
		account *= 1.08;
		account -= 100000;
		year++;
	}
	printf("%d\n", year);
	return 0;
}
