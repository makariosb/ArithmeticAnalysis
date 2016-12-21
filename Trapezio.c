#include <stdio.h>
#include <math.h>

double f( double x )
{
	return exp(-x/2) + cos(3.5*x) - 3/(x-4) ;
}

int main()
{
	double x=1.0 ,n=50.0, h=1.0/n ,sum=0, I=1.98163;
	int i;
	for (i=0; i<=50 ; i++)
		{
			printf("%d\n",i);
			if (i==0 || i==50)
			{
				sum+=f(x)/2;
			}
			else
			{
				sum+=f(x);
			}
			x+=h;
		}
		
		sum= h * sum;

		printf("T=%3.8f \n\nerror=%3.5f \n",sum,fabs(I-sum));
		return 0;
}
