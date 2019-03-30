// filename: 3a.c
// must be compiled with 3b.c
#include <stdio.h>

void set_mode(int * old_mode, int new_mode);
void get_info(int mode, float * distance, float * fuel);
void show_info(int mode, float distance, float fuel);

void set_mode(int * old_mode, int new_mode)
{
	if (new_mode != 0 && new_mode != 1)
		printf("Invalid mode specified. Mode %s used.\n", *old_mode ? "1(US)" : "0(metric)");
	else
		*old_mode = new_mode;
}

void get_info(int mode, float * distance, float * fuel)
{
	if (mode) {
		printf("Enter distance traveled in miles: ");
		scanf("%f", distance);
		printf("Enter fuel consumed in gallons: ");
		scanf("%f", fuel);
	} else {
		printf("Enter distance traveled in kilometer: ");
		scanf("%f", distance);
		printf("Enter fuel consumed in liters: ");
		scanf("%f", fuel);
	}
}

void show_info(int mode, float distance, float fuel)
{
	if (mode)
		printf("Fuel consumption is %.1f miles per gallon.\n", distance / fuel);
	else
		printf("Fuel consumption is %.2f liters per 100 km.\n", fuel * 100 / distance);
}
