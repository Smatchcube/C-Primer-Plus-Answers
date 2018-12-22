#include <stdio.h>
#include <string.h>

int main(void)
{
	char word[20];
	printf("Enter a word: ");
	scanf("%s", word);
	for (int i = strlen(word) - 1; i >= 0; i--)
		printf("%c", word[i]);
	printf("\n");
	return 0;
}
