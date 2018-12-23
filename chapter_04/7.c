#include <stdio.h>
#include <float.h>

int main(void)
{
	double one_third_double = 1.0/3.0;
	float one_third_float = 1.0/3.0;

	printf("1/3 as a double:\n%.4f\n%.12f\n%.16f\n",
			one_third_double,
			one_third_double,
			one_third_double);
	printf("1/3 as a float:\n%.4f\n%.12f\n%.16f\n",
			one_third_float,
			one_third_float,
			one_third_float);
	printf("FLT_DIG = %d\n", FLT_DIG);
	printf("DBL_DIG = %d\n", DBL_DIG);

	return 0;
}

