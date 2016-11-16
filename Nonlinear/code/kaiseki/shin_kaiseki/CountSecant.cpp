/*
Secant method
*/

#include <stdio.h>
#include <math.h>
const double eps = pow(10.0, -15);
const double delta = pow(10.0, -15);

double count = 0;

double f(double x)
{
	return 5 + exp((-6)*x) - 3 * x;
}

int main()
{
	int n = 0;
	double x0 = -2.0, x1 = -1.1, x2, f0, f1, diff, delf;

	do {
		f1 = f(x1); f0 = f(x0);
		x2 = x1 - f1*(x1 - x0) / (f1 - f0);
		diff = fabs(f(x2));
		delf = fabs(x2 - x1);
		x0 = x1; x1 = x2;
		printf("%25.15e   %10.3e  \n", x1, diff);
		count++;
	} while (diff >= eps || delf >= delta);
	printf("%25.15e   %10.3e  \n", x1, diff);
	printf("Count : %f\n", count);
}
