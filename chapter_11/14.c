// use the -lm argument for compilation to tell gcc to link the math library
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	if (argc == 3)
		printf("%f\n", pow(atof(argv[1]),atoi(argv[2])));
	return 0;
}
