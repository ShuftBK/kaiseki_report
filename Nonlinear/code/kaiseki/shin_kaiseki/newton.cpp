/*
  Newton method
*/

#include <stdio.h>
#include <math.h>
const double eps = pow(10.0,-4);
const double delta = pow(10.0,-4);

double f(double x)
{
	return x*x*x-3.0*x*x+2.0;
}

double fd(double x)
{
	return 3.0*x*x-6.0*x;
}

int main()
{
	int k=0;
	double x0,x1,f0,fd0,diff,delf;

	x0=1.5;
	do{
		f0=f(x0);fd0=fd(x0);	// ���݂�x�̎���f��fd�𓱏o
		x1=x0-f0/fd0;			// ����x�𓱏o
		diff=fabs(f(x1));		// epsilon�@
		delf=fabs(x1-x0);		// delta�@
		x0=x1;					// x��u������
	}while(diff >=eps || delf >= delta);
	printf("%f  %f %f \n",x0,diff,delta);
}
