#include <stdio.h>

int main(void) {
	
	int c, b;
	scanf("%d %d", &c, &b);
	
	double result = (double) c / b;
	printf("%.10f", result);
	
	return 0;
}