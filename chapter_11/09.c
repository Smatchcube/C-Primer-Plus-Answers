#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 20

void reverse(char *);

int main(void)
{
	char s[SIZE];
	printf("Enter some text: ");
	while (fgets(s, SIZE, stdin), strcmp(s, "q\n")) {
		reverse(s);
		fputs(s, stdout);
		printf("\nEnter some text (q to quit): ");
	}
	puts("Bye");
	return 0;
}

void reverse(char *s)
{
	int len = strlen(s);
	char temp;
	for (int i = 0; i < len / 2; i++) {
		temp = s[i];
		s[i] = s[len-i-1];
		s[len-i-1] = temp;
	}
}
