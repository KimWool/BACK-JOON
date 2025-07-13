#include <stdio.h>
#include <math.h>

int main(void) {
	
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		double a, b;
		scanf("%lf %lf", &a, &b);
		
		double result = fabs(a - b);
		printf("%.1f\n", result);
	}
	
	return 0;
}