// compile with 2b.c
#include <stdio.h>

static int mode;
static float distance, fuel;

void set_mode(int m);
void get_info(void);
void show_info(void);

void set_mode(int m)
{
	if (m != 0 && m != 1)
		printf("Invalid mode specified. Mode %s used.\n", mode ? "1(US)" : "0(metric)");
	else
		mode = m;
}

void get_info(void)
{
	if (mode) {
		printf("Enter distance traveled in miles: ");
		scanf("%f", &distance);
		printf("Enter fuel consumed in gallons: ");
		scanf("%f", &fuel);
	} else {
		printf("Enter distance traveled in kilometer: ");
		scanf("%f", &distance);
		printf("Enter fuel consumed in liters: ");
		scanf("%f", &fuel);
	}
}

void show_info(void)
{
	if (mode)
		printf("Fuel consumption is %.1f miles per gallon.\n", distance / fuel);
	else
		printf("Fuel consumption is %.2f liters per 100 km.\n", fuel * 100 / distance);
}
