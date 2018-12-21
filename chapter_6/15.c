#include <stdio.h>
#include <string.h>

int main(void)
{
	char line[255];
	int i = 0;
	
	printf("Enter a line of characters: ");
	do
		scanf("%c", &line[i]);
	while (line[i++] != '\n');
	for (i -= 1; i >= 0; i--)
		printf("%c", line[i]);
	printf("\n");
	return 0;
}
