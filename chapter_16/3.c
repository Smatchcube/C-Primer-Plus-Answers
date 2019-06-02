#include <stdio.h>
#include <math.h>

struct rectangular_V {
	float x;
	float y;
};

struct polar_V {
	float magnitude;
	float angle;
};

struct rectangular_V polar_to_rect(const struct polar_V);

int main(void) {
	struct polar_V my_polar;
	struct rectangular_V my_rectangular;

	printf("Enter the magnitude of your vector: ");
	scanf("%f", &my_polar.magnitude);
	printf("Enter the angle of your vector: ");
	scanf("%f", &my_polar.angle);

	my_rectangular = polar_to_rect(my_polar);
	printf("You vector has coordinates x = %f and y = %f .\n",
	       my_rectangular.x, my_rectangular.y);
	return 0;
}

struct rectangular_V polar_to_rect(const struct polar_V pol_coord)
{
	struct rectangular_V rect_coord;
	rect_coord.x = pol_coord.magnitude * cos(pol_coord.angle);
	rect_coord.y = pol_coord.magnitude * sin(pol_coord.angle);
	return rect_coord;
}
