/*
 Bisection Method
*/

#include <stdio.h>
#include <math.h>
const double eps = pow(10.0, -15);
const double delta = pow(10.0, -15);

double f(double x)
{
	return (5+exp((-6)*x)-3*x);
}

int main()
{
	double a = 1.6, b = 1.7, c, fa, fc, diff, delf, prevc;
	int n=0;

	do{
		c=(a+b)/2; fc=f(c); fa=f(a);
		if( fc*fa < 0) b=c;
		else a=c;
		prevc = c;

		c=(a+b)/2;
		fc=f(c);fa=f(a);
		diff=fabs(fc);
		delf=fabs(c-prevc);
	} while (diff>=eps || delf>=delta);
	c=(a+b)/2;
	printf("a=%f, c=%f, b=%f, diff=%f, delf=%f \n",a,c,b,diff,delf);

}
