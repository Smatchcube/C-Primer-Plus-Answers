#include <stdio.h>

int main(void) // ask amount of water and print the number of molecules
{
	float quarts, molecules;
	printf("Enter an amount of water in quarts: ");
	scanf("%f", &quarts);

	molecules = (quarts * 95) / 3;
	printf("That's %fe24 molecules!\n", molecules);

	return 0;
}
