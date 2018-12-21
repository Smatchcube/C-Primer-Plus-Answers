#include <stdio.h>

const float CENTIMETERS_IN_FOOT = 30.48;
const int INCHES_IN_FEET = 12;

int main(void)
{
	float height, feet;
	printf("Enter a height in centimeters: ");
	scanf("%f", &height);

	while (height > 0) {
		feet = height / CENTIMETERS_IN_FOOT;
		printf("%.1f cm = %d feet, %.1f inches\n", 
				height, 
				(int) feet, 
				(feet - (int) feet) * INCHES_IN_FEET);
		printf("Enter a height in centimeters (<=0 to quit): ");
		scanf("%f", &height);
	}
	printf("bye\n");
	return 0;
}
