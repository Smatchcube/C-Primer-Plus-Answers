#include <stdio.h>

struct name {
	char first[30];
	char middle[30];
	char last[30];
};

struct profile {
	unsigned long social_security_number;
	struct name name;
};


void print_profile(const struct profile);

int main(void)
{
	struct profile employees[5] = {
		{302039823, {"Flossie", "Mona", "Dribble"}},
		{132337322, {"Theodore", "John", "Kaczynski"}},
		{562536525, {"Richard",  .last="Papillon"}},
		{932935621, {"Barack", "Hussein", "Obama"}},
		{282133631, {"George", .last="Bush"}}
	};
	for (int i = 0; i < 5; i++)
		print_profile(employees[i]);
	return 0;
}

void print_profile(const struct profile profile)
{
	printf("%s, %s", profile.name.last, profile.name.first);
	if (profile.name.middle[0] != '\0')
		printf(" %c.", profile.name.middle[0]);
	printf(" –– %d\n", profile.social_security_number);
}
