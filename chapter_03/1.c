// Integer overflow for educational reasons, discard the warning of the compiler
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) // demonstration of overflow and underflow behavior of int and float types
{
	printf("INT_MAX \t=  %d\n", INT_MAX);
	printf("INT_MAX + 1 \t= %d\n\n", INT_MAX + 1);

	printf("FLT_MAX \t=  %e\n", FLT_MAX);
	printf("FLT_MAX * 10 \t=  %e\n\n", FLT_MAX * 10);

	printf("0.000001 / 2 \t= %f\n", 0.000001 / 2);
	return 0;
}

/* Rest of file is not compiled, it's just explanation.

OUTPUT:

NT_MAX 	=  2147483647
INT_MAX + 1 	= -2147483648

FLT_MAX 	=  3.402823e+38
FLT_MAX * 10 	=  inf

0.000001 / 2 	= 0.000000

EXPLANATION:

Integer overflow seems to just go back to negative numbers, 
this make sense when we think of the representation of the number 
(the first bit represent the sign of the integer).

Float overflow works as expected in the standard (it shows inf).
Float underflow is just loosing precision.

*/
