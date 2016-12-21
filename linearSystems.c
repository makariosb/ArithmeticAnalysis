#include <stdio.h>
#include <math.h>

double det2(double a11, double a12, double a21, double a22 )
{
	return (a11 * a22) - (a21 * a12);
}

double det3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33)
{
	return ( a11 * det2(a22,a23,a32,a33) ) - ( a12 * det2(a21,a23,a31,a33) ) +  ( a13 * det2(a21,a22,a31,a32) ) ;
}

double det4(double a11, double a12, double a13, double a14, double a21,
 double a22, double a23, double a24, double a31, double a32, double a33,
  double a34, double a41, double a42, double a43, double a44)
{
	return ( a11 * det3(a22,a23,a24,a32,a33,a34,a42,a43,a44) ) - ( a12 * det3(a21,a23,a24,a31,a33,a34,a41,a43,a44) ) + ( a13 * det3(a21,a22,a24,a31,a32,a34,a41,a42,a44) ) - ( a14 * det3(a21,a22,a23,a31,a32,a33,a41,a42,a43) );

}

double f1(double x1, double x2, double x3, double x4)
{
	return 3*x2 + x3*x4 - 7.9 ;
}

double f2(double x1, double x2, double x3, double x4)
{
	return x1 + 2*x2 + x3 + 4*x4 -20.7;
}

double f3(double x1, double x2, double x3, double x4)
{
	return pow(x1,3) + pow(x3,3) + x4 - 21.218 ;
}

double f4(double x1, double x2, double x3, double x4)
{
	return pow(x1,2) + 2*x1*x2 + pow(x4,3) - 15.88 ;
}

int main()
{
	double x1=1,x2=1,x3=1,x4=1, dx1,dx2,dx3,dx4, D1,D2,D3,D4,D ;
	double error= 5 * pow(10.0,-6);
	int i=0;
	
	do{	
		i++;
		D=det4(0, 3, x4, x3, 1, 2, 1, 4, 3 * pow(x1, 2), 0, 3 * pow(x3, 2), 1, 2 * (x1 + x2), 2 * x1, 0, 3 * pow(x4, 2));
		D1=det4(-f1(x1, x2, x3, x4), 3, x4, x3, -f2(x1, x2, x3, x4), 2, 1, 4, -f3(x1, x2, x3, x4), 0, 3 * pow(x3, 2), 1, -f4(x1, x2, x3, x4), 2 * x1, 0, 3 * pow(x4, 2));
		D2=det4(0, -f1(x1, x2, x3, x4), x4, x3, 1, -f2(x1, x2, x3, x4), 1, 4, 3 * pow(x1, 2), -f3(x1, x2, x3, x4), 3 * pow(x3, 2), 1, 2 * (x1 + x2), -f4(x1, x2, x3, x4), 0, 3 * pow(x4, 2));
		D3=det4(0, 3, -f1(x1, x2, x3, x4), x3, 1, 2, -f2(x1, x2, x3, x4), 4, 3 * pow(x1, 2), 0, -f3(x1, x2, x3, x4), 1, 2 * (x1 + x2), 2 * x1, -f4(x1, x2, x3, x4), 3 * pow(x4, 2));
		D4=det4(0, 3, x4, -f1(x1, x2, x3, x4), 1, 2, 1, -f2(x1, x2, x3, x4), 3 * pow(x1, 2), 0, 3 * pow(x3, 2), -f3(x1, x2, x3, x4), 2 * (x1 + x2), 2 * x1, 0, -f4(x1, x2, x3, x4));

		dx1=D1/D;
		dx2=D2/D;
		dx3=D3/D;
		dx4=D4/D;

		x1+=dx1;
		x2+=dx2;
		x3+=dx3;
		x4+=dx4;

		printf("i=%d\n",i);
		printf("dx1=%5.5f dx2=%5.5f dx3=%5.5f dx4=%5.5f\n",dx1,dx2,dx3,dx4);
		printf("x1+dx1=%5.5f x2+dx2=%5.5f x3+dx3=%5.5f x4+dx4=%5.5f \n",x1,x2,x3,x4);
		printf("f1=%5.5f f2=%5.5f f3=%5.5f f4=%5.5f \n------------\n",f1(x1,x2,x3,x4),f2(x1,x2,x3,x4),f3(x1,x2,x3,x4),f4(x1,x2,x3,x4));


	}while(fabs(dx1) >= error || fabs(dx2) >= error || fabs(dx3) >= error || fabs(dx4) >= error);

	return 0;
}
