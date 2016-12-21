#include <math.h>
#include <stdio.h>

double det(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33)
{
	return a11 * ( a22 * a33 - a32 * a23 ) - a12 * ( a21 * a33 - a31 * a23 ) + a13 * ( a21 * a32 - a31 * a22 ) ;
}

double f1(double x1, double x2, double x3)
{
	return 3 * pow(x1,3) - 12 * pow(x2,5) + 13 * pow(x3,2) - 4 ;
}

double f2(double x1, double x2, double x3)
{
	return  pow(x1,4) + 2 * pow(x2,2) - 12 * pow(x3,5) + 9 ;
}

double f3(double x1, double x2, double x3)
{
	return  pow(x1,2) - 2 * pow(x2,2) + 2 * pow(x3,3) - 1 ;
}

int main()
{
	double x1=1.5,x2=1.5,x3=1.5, dx1,dx2,dx3, D1,D2,D3,D, error= 0.5 * pow(10.0,-8) ;
	int i=0;

	do{
		i++;
		D=det(9 * pow(x1,2) , -60*pow(x2,4), 26*x3, 4*pow(x1,3), 4*x2, -60*pow(x3,4), 2*x1, -4*x2, 6*pow(x3,2) );
		D1=det(-f1(x1,x2,x3), -60*pow(x2,4), 26*x3, -f2(x1,x2,x3), 4*x2, -60*pow(x3,4), -f3(x1,x2,x3), -4*x2, 6*pow(x3,2) );
		D2=det(9 * pow(x1,2) , -f1(x1,x2,x3), 26*x3, 4*pow(x1,3), -f2(x1,x2,x3), -60*pow(x3,4), 2*x1, -f3(x1,x2,x3), 6*pow(x3,2) );
		D3=det(9 * pow(x1,2) , -60*pow(x2,4), -f1(x1,x2,x3), 4*pow(x1,3), 4*x2, -f2(x1,x2,x3), 2*x1, -4*x2, -f3(x1,x2,x3) );

		dx1=D1/D;
		dx2=D2/D;
		dx3=D3/D;

		x1+=dx1;
		x2+=dx2;
		x3+=dx3;

		printf("i= %d\n",i);
		printf("dx1=%3.8f dx2=%3.8f dx3=%3.8f \n",dx1,dx2,dx3);
		printf("x1=%3.8f x2=%3.8f x3=%3.8f \n",x1,x2,x3);
		printf("f1=%3.8f f2=%3.8f f3=%3.8f \n------------\n\n",f1(x1,x2,x3), f2(x1,x2,x3), f3(x1,x2,x3));
	}while (fabs(dx1)>=error || fabs(dx2)>=error || fabs(dx3)>=error);

	return 0;
}
