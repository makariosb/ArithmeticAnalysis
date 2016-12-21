#include <stdio.h>
#include <math.h>

double g(double x);
double absolute(double a,double b);

int main(){
	int i=1;
	double xn=0,xnn;
	puts("Arxiko x0?: ");
	scanf("%lf",&xnn);
	do{
		xn=xnn;
		xnn=g(xn);
		printf("%d) %.5f\n",i++,xnn);
	}while(fabs(xnn-xn)>5*pow(10,-5));
	printf("Answer is: %1.5f \n",xnn );
	return 0;
}

double g(double x){
	double k=exp(x*x*cos(x));
	double l=2*x*cos(x)-pow(x,2)*sin(x);
	double final= x-(k+12*x-15)/(k*l+12);
	return final;
}

