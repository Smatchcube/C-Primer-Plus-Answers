#include <stdio.h>
#include <ctype.h>
#define SIZE 5

void fill(int n, char [n]);

int main(void)
{
	char arr[SIZE];
	fill(SIZE, arr);
	printf("Array filled : [");
	for (int i = 0; i < SIZE; i++)
		printf("'%c', ", arr[i]);
	printf("\b\b]\n");
	return 0;
}

void fill(int n, char ar[n])
{
	for (int i = 0; i < n; i++)
		ar[i] = getchar();
}
