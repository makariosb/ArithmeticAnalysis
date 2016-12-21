#include <stdio.h>
#include <math.h>

double f( double x )
{
	return exp(-x/2) + cos(3.5*x) - 3/(x-4) ;
}

double F(double t)
{
	return f(0.5*t + 3.0/2.0);
}

double sum2(void)
{
	double sum=0.0;
	int i=0;
	double t[2]= {-0.577350269189626,0.577350269189626};
	double w[2] = {1.0, 1.0 };

	for (i=0;i<2;i++){

		sum+= w[i] * F(t[i]);
	}
	sum= 0.5 * sum;
	return sum;
}

double sum3(void)
{
	double sum=0.0;
	int i=0;
	double t[3]= {0.0, -0.774596669241483, 0.774596669241483};
	double w[3] = {0.888888888888889, 0.555555555555556, 0.555555555555556 };

	for (i=0;i<3;i++){

		sum+= w[i] * F(t[i]);
	}
	sum= 0.5 * sum;
	return sum;
}

double sum5(void)
{
	double sum=0.0;
	int i=0;
	double t[5]= {0.0, 0.538469310105683, -0.538469310105683, 0.906179845938664, -0.906179845938664 };
	double w[5] = { 0.568888888888889, 0.478628670499366, 0.478628670499366, 0.236926885056189, 0.236926885056189  };

	for (i=0;i<5;i++){

		sum+= w[i] * F(t[i]);
	}
	sum= 0.5 * sum;
	return sum;
}

int main()
{
	double I=1.981631998;
	

	printf("I2=%3.8f \n\n---------\n\nI3=%3.8f \n\n---------\n\nI5=%3.8f\n", sum2() ,sum3() ,sum5() );
	return 0;
}
