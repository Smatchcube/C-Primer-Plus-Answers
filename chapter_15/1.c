#include <stdio.h>
#include <string.h>

int bstoi(const char *);

int main(void)
{
	char * bs1 = "101";
	char * bs2 = "11111110";
	printf("%d\n", bstoi(bs1));
	printf("%d\n", bstoi(bs2));
	return 0;
}

int bstoi(const char * bs)
{
	int return_value = 0;
	for (int n = strlen(bs) - 1; n >= 0; --n) {
		if (*bs++ == '1')
			return_value += 1<<n;
	}
	return return_value;
}
