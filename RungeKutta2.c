#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double f(double x, double y)
{
	return -100.0*y + 5.0 * pow(x,3.0/2) * (1.0 + 40.0 * x);
}

double K1(double x, double y, double h)
{
	return h * f(x,y); 
}

double K2(double x, double y, double h)
{
	return h * f( x+h, y+K1(x,y,h) );
}

int main(int argc, char const *argv[])
{
	double x=0.0, h0=sqrt(0.0004), h1=h0/2.0, h2=h0/4.0, yh0=0.0, yh1=0.0, yh2=0.0;
	int n,nh0=0, nh1=0, nh2=0;
	for (n=0; x<=1.00; n++)
	{
		if (n%1==0)
		{
			yh2= yh2 + 0.5*( K1(x,yh2,h2) + K2(x,yh2,h2) );
			nh2++;	
		}
		if (n%2==0)
		{
			yh1= yh1 + 0.5*( K1(x,yh1,h1) + K2(x,yh1,h1) );
			nh1++;	
		}
		if (n%4==0)
		{
			yh0= yh0 + 0.5*( K1(x,yh0,h0) + K2(x,yh0,h0) );
			nh0++;	
		}
		if(nh2==8 || nh2%40==0 && x!=0.0 )
		{
			printf("x	n0	yh0		nh1		yh1		e[0,1]	nh2	yh2		e[1,2]\n%1.2f	%d	%1.6f	%d	   	%1.7f	%d  	%d  	%1.7f	%d\n\n\n",x,nh0,yh0,nh1,yh1,fabs(yh0-yh1)<0.0005?0:1,nh2,yh2,fabs(yh2-yh1)<0.0005?0:1);
		}

		x+=h2;
		
	}
	

	return 0;
}
