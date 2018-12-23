#include <stdio.h>

int main(void)
{
	int n, i = 0;
	printf("Enter an integer: ");
	scanf("%d", &n);
	n = n + 10;

	while (i <= n)
		printf("%d\n", i++);
	return 0;
}
