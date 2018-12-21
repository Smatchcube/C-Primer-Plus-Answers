#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

char get_choice(void);
char get_first(void);
float get_first_operand(void);
float get_second_operand(void);
float get_denominator(void);
void print_result(char, float, float, float);

int main(void)
{
	float first_operand, second_operand, result;
	char ch, operator;

	while ((ch = get_choice()) != 'q') {
		switch (ch) {
		case 'a':
			operator = '+';
			first_operand = get_first_operand();
			second_operand = get_second_operand();
			result = first_operand + second_operand;
			break;
		case 's':
			operator = '-';
			first_operand = get_first_operand();
			second_operand = get_second_operand();
			result = first_operand - second_operand;
			break;
		case 'm':
			operator = '*';
			first_operand = get_first_operand();
			second_operand = get_second_operand();
			result = first_operand * second_operand;
			break;
		case 'd':
			operator = '/';
			first_operand = get_first_operand();
			second_operand = get_denominator();
			result = first_operand / second_operand;
			break;
		default:
			printf("Operation not available, try again.\n");
			continue;
		}
		print_result(operator, first_operand, second_operand, result);
	}
	printf("Bye.\n");

	return 0;
}

char get_choice(void)
{
	char ch;
	printf("Enter the operation of your choice:\n"
	       "a. add           s. substract\n"
	       "m. multiply      d. divide\n"
	       "q. quit\n");
	while (true) {
		switch (ch = get_first()) {
		case 'a':
		case 's':
		case 'm':
		case 'd':
		case 'q':
			break;
		default:
			printf("Please respond with a, s, m, d or q.\n");
			continue;
		}
		break;
	}
	return ch;
}

char get_first(void) // same as exercise 6 from the same chapter
{
	int ch;
	while (isspace((ch = getchar())))
		continue;
	while (getchar() != '\n')
		continue;
	return ch;
}

float get_first_operand(void)
{
	float operand;
	char ch;
	printf("Enter first number: ");
	while (scanf("%f", &operand) != 1) {
		while ((ch = getchar()) != '\n') // echo input
			putchar(ch);
		printf(" is not a number.\n");
		printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
	}
	return operand;
}

float get_second_operand(void)
{
	float operand;
	char ch;
	printf("Enter second number: ");
	while (scanf("%f", &operand) != 1) {
		while ((ch = getchar()) != '\n') // echo input
			putchar(ch);
		printf(" is not a number.\n");
		printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
	}
	return operand;
}

float get_denominator(void)
{
	float denominator;
	char ch;
	printf("Enter first number: ");
	while (true) {
		while (scanf("%f", &denominator) != 1) {
			while ((ch = getchar()) != '\n') // echo input
				putchar(ch);
			printf(" is not a number.\n");
			printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
		}
		if (denominator != 0)
			return denominator;
		printf("Enter a number other than 0: ");
	}
}

void print_result(char operator, float first_operand, float second_operand, float result)
{
	printf("%f %c %f = %f\n", first_operand, operator, second_operand, result);
}
