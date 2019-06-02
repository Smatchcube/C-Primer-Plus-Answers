#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void wait(const double seconds);

int main(int argc, char * argv[]) {
	if (argc > 2) {
		printf("Too many arguments.\n");
		exit(EXIT_FAILURE);
	} else if (argc == 2) {
		puts("Waiting...");
		wait(atof(argv[1]));
		puts("Done!");
	} else {
		double seconds;
		printf("Enter the number of seconds you want to wait: ");
		scanf("%lf", &seconds);
		puts("Waiting...");
		wait(seconds);
		puts("Done!");
	}
	return 0;
}

void wait(const double seconds)
{
	clock_t start = clock();

	while ((double) (clock() - start) / CLOCKS_PER_SEC < seconds)
		continue;

	return;
}
