#include <stdio.h>
#include <math.h>

void transform(const double *, double *, int size, double (* fp)(double)); 
int main(void)
{
	double arr1[3] = {0.1, 0.2, 0.3};
	double arr2[3];
	double arr3[3];
	double arr4[3];
	double arr5[3];

	transform(arr1, arr2, 3, sin);
	transform(arr2, arr3, 3, cos);
	transform(arr3, arr4, 3, acos);
	transform(arr4, arr5, 3, asin);

	printf("%lf\n%lf\n%lf\n", arr5[0], arr5[1], arr5[2]);
	
	return 0;
}

void transform(const double *source, double *target, int size, double (* fp)(double))
{
	for (int i = 0; i < size; ++i)
		target[i] = fp(source[i]);
}
