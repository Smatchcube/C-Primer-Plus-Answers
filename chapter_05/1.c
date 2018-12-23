// converts minutes to hours and minutes
#include <stdio.h>

int const MINUTES_IN_HOUR = 60;

int main(void)
{
	int minutes;
	printf("Enter a number of minutes: ");
	scanf("%d", &minutes);
	while (minutes > 0) {
		printf("%d minutes is %d hours and %d minutes.\n",
				minutes, minutes / MINUTES_IN_HOUR, minutes % MINUTES_IN_HOUR);
		printf("Enter the next number of minutes (<=0 to quit): ");
		scanf("%d", &minutes);
	}
	printf("Done\n");
	return 0;
}
