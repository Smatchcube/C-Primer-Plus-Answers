#include <stdio.h>
#include <string.h>
#define SIZE1 10
#define SIZE2 100

char *mystrncpy(char *target,const char *source, int);

int main(void)
{
	char s1[SIZE1];
	char s2[SIZE2];
	printf("Enter some text: ");
	while (fgets(s2, SIZE2, stdin), strcmp(s2, "q\n")) {
		mystrncpy(s1, s2, SIZE1);
		printf("The first %d characters copied: %s\n", SIZE1, s1);
		for (int i = 0; i < SIZE1; ++i)
			printf("'%d'", s1[i]);
		putchar('\n');
		printf("Enter some text (q to quit): ");
	}
	puts("Bye");
	return 0;
}

char *mystrncpy(char *target,const char *source, int n)
{
	char *ret = target;
	while (*source && n > 0) {
		*target++ = *source++;
		n--;
	}
	if (n > 0)
		*target = '\0';
	return ret;
}
