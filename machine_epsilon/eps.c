#include <stdio.h>


// eps(a) is the smallest positive floating point number such that a + eps(a) != a


float eps_fp32(float a) {
	float x, y;


	if (a + 1.0f == a) {
		for (x = 2.0f; (x + a) == a; x = x * 2.0f);
	}
	else {
		x = 1.0f;

		while (1) {
			y = x / 2.0f;

			if ((y + a) != a) {
				x = y;
			}
			else {
				break;
			}
		}
	}


	return x;
}


double eps_fp64(double a) {
	double x, y;


	if (a + 1.0 == a) {
		for (x = 2.0; (x + a) == a; x = x * 2.0);
	}
	else {
		x = 1.0;

		while (1) {
			y = x / 2.0;

			if ((y + a) != a) {
				x = y;
			}
			else {
				break;
			}
		}
	}


	return x;
}


int main() {
	printf("eps(fp32) %g\n", eps_fp32(1.0f));
	printf("eps(fp64) %g\n", eps_fp64(1.0));

	return 0;
}
