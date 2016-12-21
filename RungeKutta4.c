#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double f(double x, double y1, double y2)
{
	return y2;
}

double g(double x, double y1, double y2)
{
	return -y1 / pow(x, 2.0) - 3.0 * y2 / x;
}

int main(int argc, char const *argv[])
{
	double y1=2.0,y2=-2.0,h=0.0005,x=1.0, K1,K2,K3,K4,L1,L2,L3,L4;
	int n;

	for (n=0;x<=2;x+=h)
	{	
		
		K1 = h * f(x, y1, y2);
        L1 = h * g(x, y1, y2);
        K2 = h * f(x + h / 2.0, y1 + K1 / 2.0, y2 + L1 / 2.0);
        L2 = h * g(x + h / 2.0, y1 + K1 / 2.0, y2 + L1 / 2.0);
        K3 = h * f(x + h / 2.0, y1 + K2 / 2.0, y2 + L2 / 2.0);
        L3 = h * g(x + h / 2.0, y1 + K2 / 2.0, y2 + L2 / 2.0);
        K4 = h * f(x + h, y1 + K3, y2 + L3);
        L4 = h * g(x + h, y1 + K3, y2 + L3);

		y1 = y1 + (K1 + 2 * K2 + 2 * K3 + K4) / 6.0;
        y2 = y2 + (L1 + 2 * L2 + 2 * L3 + L4) / 6.0;
		if(n%400==0 && n!=0)
			printf("x	y1	\n%1.1f	%1.10f\n\n\n",x,y1);
		n++;
	}
	return 0;
}
