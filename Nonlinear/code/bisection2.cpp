/*
 Bisection Method
*/
#include <stdio.h>
#include <math.h>

double f(double x)
{
	return (5+exp((-6)*x)-3*x);
}

int main()
{
	double a=-100, b=100, c, fa, fc, diff, delf, prevc, eps=pow(10.0,-5), delta=pow(10.0,-5);
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
