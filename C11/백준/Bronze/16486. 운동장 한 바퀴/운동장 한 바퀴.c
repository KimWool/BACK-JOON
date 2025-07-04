#include <stdio.h>

int main(void){
	
	int d1, d2;
	scanf("%d %d", &d1, &d2);
	
	float pie = 3.141592F;
	float length = (2 * d1) + (d2 * 2 * pie);
	
	printf("%f", length);
}