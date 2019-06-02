#include <stdio.h>
#define HARMONIC_MEAN(X,Y) \
	(1/((1/(float)(X) + 1/(float)(Y))/2))

int main(void) {
	float x, y;
	printf("Enter two non-zero numbers: ");
	scanf("%f %f", &x, &y);
	printf("The harmonic mean of %f and %f is %f .\n",
	       x, y, HARMONIC_MEAN(x, y));
	return 0;
}
