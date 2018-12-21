#include <stdio.h>

int main(void)
{
	float height;
	char name[20];

	printf("Enter your name: ");
	scanf("%s", name);
	printf("Enter your height in centimeters: ");
	scanf("%f", &height);

	printf("%s, you are %.3f meter tall.\n", name, height / 100);

	return 0;
}
