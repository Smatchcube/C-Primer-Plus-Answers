#include <stdio.h>

int bit(int n, int pos);

int main(void)
{
	int n, pos;
	printf("Enter one integer and a positive integer,"
	       " non-numeric value to quit.\ninput: ");
	while (scanf("%d%d", &n, &pos) == 2)
		printf("The bit at the position %d of %d is %s.\ninput: ",
		       pos, n, (bit(n, pos) == 1) ? "on" : "off");
	puts("Bye");
	return 0;
}

int bit(int n, int pos)
{
	return (n >> pos) & 1;
}
