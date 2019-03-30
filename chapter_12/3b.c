// filename: 3b.c
// must be compiled with 3a.c
#include <stdio.h>
#include "3a.h"

int main(void)
{
	int mode = 0;
	int new_mode;
	float distance, fuel;

	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d", &new_mode);
	while (new_mode >= 0)
	{
		set_mode(&mode, new_mode);
		get_info(mode, &distance, &fuel);
		show_info(mode, distance, fuel);
		printf("Enter 0 for metric mode, 1 for US mode");
		printf(" (-1 to quit): ");
		scanf("%d", &new_mode);
	}
	printf("Done.\n");
	return 0;
}
