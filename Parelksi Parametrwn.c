#include <math.h>
#include <stdio.h>

double det(double x11, double x12, double x21, double x22)
{
	return x11 * x22 - x21 * x12 ;
}

double s1(double x1,double x2, double k )
{
	return pow(x1,3) + 2 * x2 - 21 * (1 - k/10.0) ;
}

double s2(double x1, double x2)
{
	return 7 * x1 + pow(x2,2) - 30 ;
}

int main()
{
	double x1=3,x2=-3, dx1, dx2, D1,D2,D, error= 0.5 * pow(10.0,-5);
	int i=0,k=1;

	for (k=1; k<=10; k++){
		do{
			i++;
			D=det(3 * pow(x1,2), 2, 7, 2 * x2);
			D1=det(-s1(x1,x2,k), 2, -s2(x1,x2), 2*x2);
			D2=det(3 * pow(x1,2), -s1(x1,x2,k), 7, -s2(x1,x2));
			dx1=D1/D;
			dx2=D2/D;
			x1+=dx1;
			x2+=dx2;
			printf("i= %d	k=%d\nx1= %3.5f	x2= %3.5f\n------\n",i,k,x1,x2);
		}while( fabs(dx1)>= error || fabs(dx2)>= error);

	}

	/*printf("i= %d\n------\nx1= %3.5f	x2= %3.5f",i,x1,x2);*/

	return 0;
}
