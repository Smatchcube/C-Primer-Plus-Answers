#include <stdio.h>

int calls = 0;

void foo(void);

int main(void)
{
	for (int i = 0; i < 10; ++i) {
		foo();
	}
}

void foo(void)
{
	printf("I was called %d time%s previously!\n", calls, calls == 1 ? "" : "s");
	++calls;
}
