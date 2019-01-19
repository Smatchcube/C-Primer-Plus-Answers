#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
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
	int i = 0;
	do
		ar[i] = getchar();
	while (!isblank(ar[i++]) && i < n);
}
