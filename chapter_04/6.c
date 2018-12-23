#include <stdio.h>
#include <string.h>

int main(void)
{
	char first_name[20], last_name[20];
	int first_name_len, last_name_len;

	printf("Enter your first name: ");
	scanf("%s", first_name);
	printf("Enter your last name: ");
	scanf("%s", last_name);

	first_name_len = strlen(first_name);
	last_name_len = strlen(last_name);

	printf("%s %s\n", first_name, last_name);
	printf("%*d %*d\n",
			first_name_len, first_name_len,
			last_name_len, last_name_len);
	printf("%s %s\n", first_name, last_name);
	printf("%-*d %-*d\n",
			first_name_len, first_name_len,
			last_name_len, last_name_len);

	return 0;
}
