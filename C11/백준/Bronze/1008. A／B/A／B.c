#include <stdio.h>

int main(void){
	
	double A = 0;
	double B = 0;
	scanf("%lf %lf", &A, &B);
	
    double div = A / B;
	printf("%.9f", div);
	
	return 0;
} 