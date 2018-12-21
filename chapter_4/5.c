#include <stdio.h>

int main(void)
{
	float download_speed, size;
	printf("Enter your download speed in megabits per seconds: ");
	scanf("%f", &download_speed);
	printf("Enter the size of the file in megabytes: ");
	scanf("%f", &size);

	printf("At %.2f megabits per second, a file of %.2f megabytes downloads in %.2f seconds.\n",
			download_speed,
			size,
			size * 8 / download_speed);

	return 0;
}
