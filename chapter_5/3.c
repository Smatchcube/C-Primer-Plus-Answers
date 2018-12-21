#include <stdio.h>

int main(void)
{
	int days;

	printf("Enter the number of days: ");
	scanf("%d", &days);
	while (days > 0) {
		printf("%d days are %d weeks, %d days.\n",
				days, days / 7, days % 7);
		printf("Enter a number of days (<=0 to quit): ");
		scanf("%d", &days);
	}
	printf("Done\n");
	return 0;
}
