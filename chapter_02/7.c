#include <stdio.h>

void smile(void);

int main(void) /* this program share smiles */
{
	smile();
	smile();
	smile();
	printf("\n");
	smile();
	smile();
	printf("\n");
	smile();
	printf("\n");
}

void smile(void)
{
	printf("Smile!");
}
