#include <stdio.h>
#include <ctype.h>
#include <math.h>

int atoi(const char *);

int main(void)
{
	char s[20];
	printf("Enter an integer: ");
	fgets(s, 20, stdin);
	printf("Here is your integer doubled: %d\n", atoi(s) * 2);
	return 0;
}

int atoi(const char *s)
{
	int nb_digits = 0;
	const char *start_number;
	int ret_val = 0;
	while (*s && isspace(*s))
		++s;
	if (!isdigit(*s)) {
		return 0;
	} else {
		start_number = s;
		while (*s && isdigit(*s)) {
			++nb_digits;
			++s;
		}
		for (int i = nb_digits - 1; i >= 0; --i)
			ret_val += (*start_number++ - '0') * pow(10, i);
	}
	return ret_val;
}
